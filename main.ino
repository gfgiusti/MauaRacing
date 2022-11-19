#include "ESP32CAN.h"
#include <CAN_config.h>
#include "mensagens.h"
#include "pedal.h"

// Pin Declaration
// Output pins:
const uint8_t kl15ActPin = 32;          // GPIO32 - Board D32  ---- Output to actuate 12V contactor to BRM;
//const uint8_t kl15StateLightPin = 2;    // GPIO2 - Onboard LED  ---- Output to indicator LED of 12V power supply to BRM;
const uint8_t kl50ActPin = 33;          // GPIO33 - Board D33  ----- Output to actuate 48V contactor to BRM;
//const uint8_t kl50StateLightPin = 27;   // GPIO7 - Board D27  ----- Output to indicator LED of 48V power supply to BRM;
//const uint8_t brmRunStateLightPin = 14; // GPIO14 - Board D14  ---- Output to indicator LED of "Ready to Run" status on BRM;

// Input Pins:
const uint8_t kl50SwPin = 34;  // GPIO 34 - Board D34  ---- Input to read the button and activate 48V contactor;
const uint8_t brakeSwPin = 35; 
// Const Values
const int maxPower = 1000;

// Global variables

static int rpm = 0;
static int modeoper = 0;
static float torque = 0.0;

// State variables
static bool kl15ActState = LOW;   // Variable to indicate if BRM 12V is activated;
static bool kl50ActState = LOW;   // Variable to indicate if BRM 48V is activated;
static bool brmRunInib = 1;       // Variable to indicate BRM is in RTR state;
static bool brmTqMdInib = 1;
static bool brkState = LOW;       // Defines brake state as high so it must be pressed to kl50 on;

// Time Variables:
int currentMillis = 0;
int lastTrg = 0;
int trgInterval = 3000; // SW filter to allow kl50 request once in a 3 second time interval;

CAN_device_t CAN_cfg;





// States possible repetition intervals for CAN messages
const uint8_t mstime10 = 10;
const uint8_t mstime100 = 100;

// Declares the cores used to run the tasks
const uint8_t taskCoreZero = 0;
const uint8_t taskCoreOne = 1;

// Tasks declaration
static void vTX_Pt_Edrv_Des_1(void *);
static void vTX_Eem_Edrv_Lim_1(void *);
static void vTX_Pt_Veh_1(void *);
static void vRX (void*);
//static void vCheckStOperMod (void*);
//static void vTX_Task_Create (void*);


//static void vTorqueMap(void *);
static void pinModeDeclaration();
static void attachInterruption();
void IRAM_ATTR checkBrkState();
void IRAM_ATTR kl50ActRequest();


// Criação de Handlers
//static TaskHandle_t xLiberaComando = NULL;
// static void vPEDAL(void *);
// static void vCHECKCAN(void *);

static void pinModeDeclaration() // Configures ESP32 pins mode of operation
{
  // OutputPins:
  pinMode(kl15ActPin, OUTPUT);
  //pinMode(kl15StateLightPin, OUTPUT);
  pinMode(kl50ActPin, OUTPUT);
  //pinMode(brmRunStateLightPin, OUTPUT);

      // InputPins:
  pinMode(kl50SwPin, INPUT_PULLDOWN);
  pinMode(brakeSwPin, INPUT_PULLDOWN);
}

static void attachInterruption() // Attributes Input pins to HW interruptions
{
  attachInterrupt(kl50SwPin, kl50ActRequest, CHANGE); // Calls the interruption routine "kl50Request" once kl50SwPin gets a changing edge;
  //attachInterrupt(brakeSwPin, checkBrkState, CHANGE); // Calls the interruption to evaluate brake status every time there is a change of state in the digital brake signal pin;
}

static void activateKl15() // Activates 12V contactor to BRM
{
  kl15ActState = HIGH;
  digitalWrite(kl15ActPin, kl15ActState);
}

void IRAM_ATTR checkBrkState() // used to check if brake pedal is pressed;
{
  brkState = digitalRead(brakeSwPin);
}

void IRAM_ATTR kl50ActRequest()
{
  brkState = digitalRead(brakeSwPin);
  currentMillis = millis();
    lastTrg=currentMillis;
    if (brkState == HIGH && brmRunInib == LOW)
    {
      if (digitalRead(kl50SwPin) == HIGH)
      {
        kl50ActState = HIGH;      
      }
    }
     if (digitalRead(kl50SwPin)==LOW)
      {
        kl50ActState = LOW;
      }
      digitalWrite(kl50ActPin, kl50ActState);
}


void setup()
{
  Serial.begin(115200);
  pinModeDeclaration();
  attachInterruption();
  ADS_Startup ();
  // CAN Configuration
  CAN_cfg.tx_pin_id = GPIO_NUM_5;
  CAN_cfg.rx_pin_id = GPIO_NUM_4;
  CAN_cfg.speed = CAN_SPEED_500KBPS;
  CAN_cfg.rx_queue = xQueueCreate(10,sizeof(CAN_frame_t));

  // Initialize CAN
  CAN_init();

  // Configures ID and data lengh of CAN messages used


  Serial.println("KL15 off");
  delay(200);
  // Início do envio das mensagens
  xTaskCreatePinnedToCore(vTX_Eem_Edrv_Lim_1, "EnviaEem_Edrv_Lim_1", 4096, NULL, 1, NULL, taskCoreZero);
  delay(100);
  xTaskCreatePinnedToCore(vTX_Pt_Edrv_Des_1, "EnviaPt_Edrv_Des_1", 4096, NULL, 1, NULL, taskCoreZero);
  delay(100);
  xTaskCreatePinnedToCore(vTX_Pt_Veh_1, "EnviaPt_Veh_1", 4096, NULL, 1, NULL, taskCoreZero);
  delay(100); 
  xTaskCreatePinnedToCore(vRX, "Le RX", 4096, NULL, 1, NULL, taskCoreOne);
  delay(200);
  // Comando de contato
  activateKl15();
  Serial.println("KL15 on");
  delay(500);


//  xTaskCreatePinnedToCore(vCheckStOperMod, "ConfereKL15", 4096, NULL, 1, xLiberaComando, NULL);
//  xTaskCreatePinnedToCore(vTX_Task_Create, "ConfereKL15", 4096, NULL, 1, xLiberaComando, taskCoreZero);
  
  while (brmRunInib == 1){
    CheckStOperMod();
  }
}

// função de tarefa
static void vTX_Pt_Edrv_Des_1(void *pvParameters)
{
  Pt_Edrv_Des_Data Pt_Edrv_Des_Data;
  Pt_Edrv_Des_Val Pt_Edrv_Des_Val;
  TickType_t myLastUnblock = xTaskGetTickCount();
  CAN_frame_t Pt_Edrv_Des_1;
  Pt_Edrv_Des_1.MsgID = 0x1;
  Pt_Edrv_Des_1.FIR.B.DLC = 7;
  for (;;)
  { 
  if (modeoper == 1){
    Pt_Edrv_Des_Val.Pt_stOperModDesEdrv = 1;
    ler_pedal();
//    
    if (PPS < 0.05 || brkState == HIGH){
      torque = 0.01;
   }else 
    torque = (PPS * maxPower)/(((float)rpm+6)/60*2*3.14);
    Pt_Edrv_Des_Val.Pt_tqDesEdrv = (torque+200)*10;

    Serial.println(PPS);
  }
//    
    atualizaTX_Pt_Edrv_Des_1(&Pt_Edrv_Des_Val, &Pt_Edrv_Des_Data);
    Pt_Edrv_Des_1.data.u8[0] = Pt_Edrv_Des_Data.Pt_Edrv_Des_6;
    Pt_Edrv_Des_1.data.u8[1] = Pt_Edrv_Des_Data.Pt_Edrv_Des_5;
    Pt_Edrv_Des_1.data.u8[2] = Pt_Edrv_Des_Data.Pt_Edrv_Des_4;
    Pt_Edrv_Des_1.data.u8[3] = Pt_Edrv_Des_Data.Pt_Edrv_Des_3;
    Pt_Edrv_Des_1.data.u8[4] = Pt_Edrv_Des_Data.Pt_Edrv_Des_2;
    Pt_Edrv_Des_1.data.u8[5] = Pt_Edrv_Des_Data.Pt_Edrv_Des_1;
    Pt_Edrv_Des_1.data.u8[6] = Pt_Edrv_Des_Data.Pt_Edrv_Des_0;
    CAN_write_frame(&Pt_Edrv_Des_1);
    vTaskDelayUntil(&myLastUnblock, 8/ portTICK_RATE_MS);
  }
}
static void vTX_Eem_Edrv_Lim_1(void *pvParameters)
{
  
  Eem_Edrv_Lim_1_Data Eem_Edrv_Lim_1_Data;
  Eem_Edrv_Lim_1_Val Eem_Edrv_Lim_1_Val;
  TickType_t myLastUnblock = xTaskGetTickCount();
  CAN_frame_t Eem_Edrv_Lim_1;
  
  Eem_Edrv_Lim_1.MsgID = 0xD;
  Eem_Edrv_Lim_1.FIR.B.DLC = 8;
  for (;;)
  {
    atualizaTX_Eem_Edrv_Lim_1(&Eem_Edrv_Lim_1_Val, &Eem_Edrv_Lim_1_Data);
    Eem_Edrv_Lim_1.data.u8[0] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_7;
    Eem_Edrv_Lim_1.data.u8[1] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_6;
    Eem_Edrv_Lim_1.data.u8[2] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_5;
    Eem_Edrv_Lim_1.data.u8[3] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_4;
    Eem_Edrv_Lim_1.data.u8[4] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_3;
    Eem_Edrv_Lim_1.data.u8[5] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_2;
    Eem_Edrv_Lim_1.data.u8[6] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_1;
    Eem_Edrv_Lim_1.data.u8[7] = Eem_Edrv_Lim_1_Data.Eem_Edrv_Lim_1_0;
    CAN_write_frame(&Eem_Edrv_Lim_1);
  //  Serial.println("mandei");
    vTaskDelayUntil(&myLastUnblock, 10 / portTICK_RATE_MS);
  }
}

static void vTX_Pt_Veh_1(void *pvParameters)
{
  Pt_Veh_1_Data Pt_Veh_1_Data;
  Pt_Veh_1_Val Pt_Veh_1_Val;
  TickType_t myLastUnblock = xTaskGetTickCount();
  CAN_frame_t Pt_Veh_1;
    Pt_Veh_1.MsgID = 0x10;
  Pt_Veh_1.FIR.B.DLC = 8;
  for (;;)
  {
    atualizaTX_Pt_Veh_1(&Pt_Veh_1_Val, &Pt_Veh_1_Data);
    Pt_Veh_1.data.u8[0] = Pt_Veh_1_Data.Pt_Veh_1_7;
    Pt_Veh_1.data.u8[1] = Pt_Veh_1_Data.Pt_Veh_1_6;
    Pt_Veh_1.data.u8[2] = Pt_Veh_1_Data.Pt_Veh_1_5;
    Pt_Veh_1.data.u8[3] = Pt_Veh_1_Data.Pt_Veh_1_4;
    Pt_Veh_1.data.u8[4] = Pt_Veh_1_Data.Pt_Veh_1_3;
    Pt_Veh_1.data.u8[5] = Pt_Veh_1_Data.Pt_Veh_1_2;
    Pt_Veh_1.data.u8[6] = Pt_Veh_1_Data.Pt_Veh_1_1;
    Pt_Veh_1.data.u8[7] = Pt_Veh_1_Data.Pt_Veh_1_0;
    CAN_write_frame(&Pt_Veh_1);
    vTaskDelayUntil(&myLastUnblock, 100 / portTICK_RATE_MS);
  }
}





static void vRX(void *pvParameters){
    Edrv_Act_1_Data Edrv_Act_1_Data;
    Edrv_Act_1_Val Edrv_Act_1_Val;
    TickType_t myLastUnblock = xTaskGetTickCount();
    CAN_frame_t Edrv_Act_1;
    
    for (;;){
    if (xQueueReceive(CAN_cfg.rx_queue, &Edrv_Act_1, 3 * portTICK_PERIOD_MS) == pdTRUE) {
    if (Edrv_Act_1.MsgID == 0x2) {        
        Edrv_Act_1_Data.Edrv_Act_1_7 = Edrv_Act_1.data.u8[0];
        Edrv_Act_1_Data.Edrv_Act_1_6 = Edrv_Act_1.data.u8[1];
        Edrv_Act_1_Data.Edrv_Act_1_5 = Edrv_Act_1.data.u8[2];
        Edrv_Act_1_Data.Edrv_Act_1_4 = Edrv_Act_1.data.u8[3];
        Edrv_Act_1_Data.Edrv_Act_1_3 = Edrv_Act_1.data.u8[4];
        Edrv_Act_1_Data.Edrv_Act_1_2 = Edrv_Act_1.data.u8[5];
        Edrv_Act_1_Data.Edrv_Act_1_1 = Edrv_Act_1.data.u8[6];
        Edrv_Act_1_Data.Edrv_Act_1_0 = Edrv_Act_1.data.u8[7];
        atualizaRX_Edrv_Act_1(&Edrv_Act_1_Val, &Edrv_Act_1_Data);
//        Edrv_nrChksAct =  Edrv_Act_1_Val.Edrv_nrChksAct_Val;
//        Edrv_nrAlvCntrAct = Edrv_Act_1_Val.Edrv_nrAlvCntrAct_Val ;
//        Edrv_stRunAct = Edrv_Act_1_Val.Edrv_stRunAct_Val  ;
//        Edrv_stOperModAct = Edrv_Act_1_Val.Edrv_stOperModAct_Val;
//        Edrv_tqAct = (Edrv_Act_1_Val.Edrv_tqAct_Val - 200) / 10.0;
        rpm = (Edrv_Act_1_Val.Edrv_nAct_Val *6 -24000);
        modeoper = Edrv_Act_1_Val.Edrv_stRunAct_Val;
//        Edrv_uAct = Edrv_Act_1_Val.Edrv_uAct_Val / 16.0;
//        Edrv_iAct = Edrv_Act_1_Val.Edrv_iAct_Val - 500 ;
        vTaskDelayUntil(&myLastUnblock, 10 / portTICK_RATE_MS);
      } 
    }
  }
}

void CheckStOperMod(){
    Edrv_Act_1_Data Edrv_Act_1_Data;
    Edrv_Act_1_Val Edrv_Act_1_Val;
    CAN_frame_t Edrv_Act_1;
    brmRunInib = 1;
    if (xQueueReceive(CAN_cfg.rx_queue, &Edrv_Act_1, 3 * portTICK_PERIOD_MS) == pdTRUE) {
    if (Edrv_Act_1.MsgID == 0x2) {        
        Edrv_Act_1_Data.Edrv_Act_1_7 = Edrv_Act_1.data.u8[0];
        Edrv_Act_1_Data.Edrv_Act_1_6 = Edrv_Act_1.data.u8[1];
        Edrv_Act_1_Data.Edrv_Act_1_5 = Edrv_Act_1.data.u8[2];
        Edrv_Act_1_Data.Edrv_Act_1_4 = Edrv_Act_1.data.u8[3];
        Edrv_Act_1_Data.Edrv_Act_1_3 = Edrv_Act_1.data.u8[4];
        Edrv_Act_1_Data.Edrv_Act_1_2 = Edrv_Act_1.data.u8[5];
        Edrv_Act_1_Data.Edrv_Act_1_1 = Edrv_Act_1.data.u8[6];
        Edrv_Act_1_Data.Edrv_Act_1_0 = Edrv_Act_1.data.u8[7];
        atualizaRX_Edrv_Act_1(&Edrv_Act_1_Val, &Edrv_Act_1_Data);
//        Edrv_nrChksAct =  Edrv_Act_1_Val.Edrv_nrChksAct_Val;
//        Edrv_nrAlvCntrAct = Edrv_Act_1_Val.Edrv_nrAlvCntrAct_Val ;
//        Edrv_stRunAct = Edrv_Act_1_Val.Edrv_stRunAct_Val  ;
//        Edrv_stOperModAct = Edrv_Act_1_Val.Edrv_stOperModAct_Val;
//        Edrv_tqAct = (Edrv_Act_1_Val.Edrv_tqAct_Val - 200) / 10.0;
//        Edrv_nAct = (Edrv_Act_1_Val.Edrv_nAct_Val - 24000) * 6;
//        Edrv_uAct = Edrv_Act_1_Val.Edrv_uAct_Val / 16.0;
//        Edrv_iAct = Edrv_Act_1_Val.Edrv_iAct_Val - 500 ;
        delay(10);
        Serial.println("Rx recebido");
        if (Edrv_Act_1_Val.Edrv_stOperModAct_Val == 0xE && Edrv_Act_1_Val.Edrv_stRunAct_Val == 0x0){
          brmRunInib = 0;

        }
      }else{
        brmRunInib = 1;
      }
 
    }
     else{
     brmRunInib = 1;
     }
}  


void loop()
{
brkState = digitalRead(brakeSwPin);

}
