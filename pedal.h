//const int analogInPin1 = 13;
//const int analogInPin2 = 12;
//
//// sinal 1 
//int sensorValue1 = 0;        
//float porcentValue1 = 0; 
//float outValue1 = 0;
//int porcentPedal1 ;
//
//// sinal 2 
//int sensorValue2 = 0;        
//float porcentValue2 = 0; 
//float outValue2 = 0;
//int porcentPedal2;
//
//// definir funçao sinal 1 
//
//void PSS1 (){
//
// // read the analog in value:
//  sensorValue1 = analogRead(analogInPin1);
//  // map it to the range of the analog out:
//  porcentValue1 = map(sensorValue1, 0,  4095, 0, 1000);
//  porcentValue1 = porcentValue1 / 10.0;
//  if (porcentValue1 <= 16){
//    outValue1 = 0;
//  }else
//  if (porcentValue1 > 16 && porcentValue1 < 87.7){
//   outValue1 = ( porcentValue1 - 10.188) / 4.0104;
//  }else
//   if (porcentValue1 >= 87.7 ){
//    outValue1 = 21;
//   }
//  int porcentValueInt1 = round(outValue1);
//  porcentPedal1 = map(porcentValueInt1, 0, 22, 0, 100);
//
//
//}
//
////definir funçao sinal 2 
//
//void  PSS2 (){
//  
//// read the analog in value:
//  sensorValue2 = analogRead(analogInPin2);
//  // map it to the range of the analog out:
//  porcentValue2 = map(sensorValue2, 0,  4095, 0, 1000);
//  porcentValue2 = porcentValue2 / 10.0;
//  if (porcentValue2 <= 7.5){
//    outValue2 = 0;
//  }else
//  if (porcentValue2 > 7.5 && porcentValue2 < 43.7){
//   outValue2 = ( porcentValue2 - 5.0938) / 2.00519143;
//  }else
//   if (porcentValue2 >= 43.7){
//    outValue2 = 21;
//   }
//   
//  int porcentValueInt2 = round(outValue2);
//  porcentPedal2 = map(porcentValueInt2, 0, 21, 0, 100);
//  
//}
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;
int16_t adc0, adc1, adc2, adc3;

float PPS;

void ADS_Startup (){
   if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
  ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
}

//Adafruit_ADS1115 ads(0x48);
//
//int16_t adc0, adc1, adc2, adc3;
//int c1, c2, c3, contador = millis();



void ler_pedal(void) 
{
int16_t adc0, adc1;
float volts0, volts1, PPS1, PPS2;
adc0 = ads.readADC_SingleEnded(0);
adc1 = ads.readADC_SingleEnded(1);
volts0 = ads.computeVolts(adc0);
volts1 = ads.computeVolts(adc1);

if (volts0 <= 0.75)
  PPS1=0;
if (volts0 >0.75)
  PPS1 = (volts0-0.75) /3.09;
if (volts0 >= 3.84)
  PPS1 = 1;


if (volts1 <= 0.375)
  PPS2=0;
if (volts1 >0.375)
  PPS2 = (volts1-0.375) /1.545;
if (volts1 >= 1.92)
  PPS2 = 1;

if (PPS1 <0)
  PPS1 = 0;
if (PPS1 >1)
  PPS1 = 1;
if (PPS2 <0)
  PPS2 = 0;
if (PPS2 <1)
  PPS2 = 1;

PPS = PPS1;

}
