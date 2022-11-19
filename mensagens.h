//------Motor Default Parameters----------------------


// Pt_Edrv_Des_1 Message:
const int Pt_nrChksActDef = 0;
const int Pt_nrAlvCntrActDef = 0;
const int Pt_stOperModDesEdrvDef = 0;
const int Pt_tqDesEdrvDef = 0;
const int Pt_tqMinEdrvDef = -50;
const int Pt_nDesEdrvDef = 0;

// Pt_Veh_1 Message:
const int Pt_nrChksIgnDef = 0;
const int Pt_nrAlvCntrIgnDef = 0;
const int Pt_stIgnSwtDef = 4;
const int Pt_nEngDef = 0;
const int Pt_vVehDef = 0;
const int Pt_tAmbEdrvDef = 120;
const int Pt_tiEdrvShOffDef = 0;
const int Pt_flgCrashDef = 0;

// Eem_Edrv_Lim_1 Message:

const int Eem_uMaxEdrvDef = 52;
const int Eem_uMinEdrvDef = 36;
const int Eem_rMvbEdrvDef = 2;
const int Eem_iReqEdrvDef = 0;
const int Eem_iMaxEdrvDef = 80;
const int Eem_iMinEdrvDef = -80;

typedef struct
{
  uint16_t Pt_Edrv_Des_0 = 0x00;
  uint16_t Pt_Edrv_Des_1 = 0x00;
  uint16_t Pt_Edrv_Des_2 = 0x00;
  uint16_t Pt_Edrv_Des_3 = 0x00;
  uint16_t Pt_Edrv_Des_4 = 0x00;
  uint16_t Pt_Edrv_Des_5 = 0x00;
  uint16_t Pt_Edrv_Des_6 = 0x00;
} Pt_Edrv_Des_Data;

typedef struct
{
  uint16_t Pt_nrChkAct= Pt_nrChksActDef;
  uint16_t Pt_nrAlvCntrAct= Pt_nrAlvCntrActDef;
  uint16_t Pt_stOperModDesEdrv= Pt_stOperModDesEdrvDef;
  uint16_t Pt_tqDesEdrv= (Pt_tqDesEdrvDef + 200)* 10;
  uint16_t Pt_tqMinEdrv= (Pt_tqMinEdrvDef + 200) * 10;
  uint16_t Pt_nDesEdrv= (Pt_nDesEdrvDef + 24000)/6;
} Pt_Edrv_Des_Val;

typedef struct
{
  uint16_t Pt_nrChksIgn = Pt_nrChksIgnDef;
  uint16_t Pt_nrAlvCntrIgn = Pt_nrAlvCntrIgnDef;
  uint16_t Pt_stIgnSwt = Pt_stIgnSwtDef;
  uint16_t Pt_nEng = Pt_nEngDef;
  uint16_t Pt_vVeh = Pt_vVehDef;
  uint16_t Pt_tAmbEdrv = Pt_tAmbEdrvDef + 40;
  uint16_t Pt_tiEdrvShOff= Pt_tiEdrvShOffDef;
  uint16_t Pt_flgCrash= Pt_flgCrashDef;
} Pt_Veh_1_Val;

typedef struct
{
  uint16_t Pt_Veh_1_0 = 0x00;
  uint16_t Pt_Veh_1_1 = 0x00;
  uint16_t Pt_Veh_1_2 = 0x00;
  uint16_t Pt_Veh_1_3 = 0x00;
  uint16_t Pt_Veh_1_4 = 0x00;
  uint16_t Pt_Veh_1_5 = 0x00;
  uint16_t Pt_Veh_1_6 = 0x00;
  uint16_t Pt_Veh_1_7 = 0x00;
} Pt_Veh_1_Data;

typedef struct
{
  uint16_t Eem_uMaxEdrv = (Eem_uMaxEdrvDef * 16);
  uint16_t Eem_uMinEdrv = (Eem_uMinEdrvDef * 16);
  uint16_t Eem_rMvbEdrv = Eem_rMvbEdrvDef;
  uint16_t Eem_iReqEdrv = Eem_iReqEdrvDef + 500;
  uint16_t Eem_iMaxEdrv = Eem_iMaxEdrvDef;
  uint16_t Eem_iMinEdrv = Eem_iMinEdrvDef + 1000;
}Eem_Edrv_Lim_1_Val;

typedef struct
{
  uint16_t Eem_Edrv_Lim_1_0 = 0x00;
  uint16_t Eem_Edrv_Lim_1_1 = 0x00;
  uint16_t Eem_Edrv_Lim_1_2 = 0x00;
  uint16_t Eem_Edrv_Lim_1_3 = 0x00;
  uint16_t Eem_Edrv_Lim_1_4 = 0x00;
  uint16_t Eem_Edrv_Lim_1_5 = 0x00;
  uint16_t Eem_Edrv_Lim_1_6 = 0x00;
  uint16_t Eem_Edrv_Lim_1_7 = 0x00;
}Eem_Edrv_Lim_1_Data;

void atualizaTX_Pt_Edrv_Des_1 (Pt_Edrv_Des_Val *Pt_Edrv_Des_Val, Pt_Edrv_Des_Data *Pt_Edrv_Des_Data)
{
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 0, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 8));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 1, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 9));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 2, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 10));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 3, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 11));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 4, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 12));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 5, 0);
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 6, 0);
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_0, 7, 0);
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 0, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 0));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 1, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 1));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 2, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 2));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 3, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 3));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 4, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 4));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 5, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 5));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 6, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 6));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_1, 7, bitRead(Pt_Edrv_Des_Val->Pt_nDesEdrv, 7));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 0, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 4));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 1, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 5));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 2, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 6));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 3, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 7));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 4, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 8));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 5, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 9));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 6, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 10));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_2, 7, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 11));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 0, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 8));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 1, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 9));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 2, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 10));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 3, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 11));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 4, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 0));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 5, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 1));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 6, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 2));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_3, 7, bitRead(Pt_Edrv_Des_Val->Pt_tqMinEdrv, 3));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 0, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 0));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 1, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 1));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 2, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 2));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 3, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 3));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 4, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 4));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 5, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 5));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 6, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 6));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_4, 7, bitRead(Pt_Edrv_Des_Val->Pt_tqDesEdrv, 7));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 0, bitRead(Pt_Edrv_Des_Val->Pt_nrAlvCntrAct, 0));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 1, bitRead(Pt_Edrv_Des_Val->Pt_nrAlvCntrAct, 1));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 2, bitRead(Pt_Edrv_Des_Val->Pt_nrAlvCntrAct, 2));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 3, bitRead(Pt_Edrv_Des_Val->Pt_nrAlvCntrAct, 3));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 4, bitRead(Pt_Edrv_Des_Val->Pt_stOperModDesEdrv, 0));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 5, bitRead(Pt_Edrv_Des_Val->Pt_stOperModDesEdrv, 1));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 6, bitRead(Pt_Edrv_Des_Val->Pt_stOperModDesEdrv, 2));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_5, 7, bitRead(Pt_Edrv_Des_Val->Pt_stOperModDesEdrv, 3));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 0, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 0));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 1, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 1));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 2, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 2));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 3, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 3));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 4, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 4));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 5, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 5));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 6, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 6));
  bitWrite(Pt_Edrv_Des_Data->Pt_Edrv_Des_6, 7, bitRead(Pt_Edrv_Des_Val->Pt_nrChkAct, 7));
}
void atualizaTX_Eem_Edrv_Lim_1 (Eem_Edrv_Lim_1_Val *Eem_Edrv_Lim_1_Val, Eem_Edrv_Lim_1_Data *Eem_Edrv_Lim_1_Data)
{
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 6));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 7));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 8));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 9));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 4, 0);
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 5, 0);
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 6, 0);
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_0, 7, 0); //byte 0
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 8));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 9));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 0));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 1));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 2));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 3));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 4));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_1, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMinEdrv, 5)); //byte 1
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv,0));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 1));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 2));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 3));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 4));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 5));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 6));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_2, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_iMaxEdrv, 7)); //byte 2
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 2));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 3));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 4));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 5));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 6));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 7));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 8));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_3, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 9)); //byte 3
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 4));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 5));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 6));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 7));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 8));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 9));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 0));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_4, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_iReqEdrv, 1)); // byte 4
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 6));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 7));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 8));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 9));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 0));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 1));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 2));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_5, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_rMvbEdrv, 3)); //byte 5
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 8));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 9));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 0));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 1));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 2));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 3));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv, 4));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_6, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMinEdrv,5)); //byte 6
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 0, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 0));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 1, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 1));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 2, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 2));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 3, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 3));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 4, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 4));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 5, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 5));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 6, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 6));
  bitWrite(Eem_Edrv_Lim_1_Data->Eem_Edrv_Lim_1_7, 7, bitRead(Eem_Edrv_Lim_1_Val->Eem_uMaxEdrv, 7)); //byte 7
}
void atualizaTX_Pt_Veh_1(Pt_Veh_1_Val *Pt_Veh_1_Val, Pt_Veh_1_Data *Pt_Veh_1_Data)
{
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 0, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 6));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 1, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 7));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 2, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 8));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 3, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 9));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 4, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 10));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 5, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 11));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 6, bitRead(Pt_Veh_1_Val->Pt_flgCrash, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_0, 7, 0);
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 0, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 6));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 1, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 7));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 2, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 3, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 4, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 5, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 3));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 6, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 4));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_1, 7, bitRead(Pt_Veh_1_Val->Pt_tiEdrvShOff, 5));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 0, bitRead(Pt_Veh_1_Val->Pt_vVeh, 10));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 1, bitRead(Pt_Veh_1_Val->Pt_vVeh, 11));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 2, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 3, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 4, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 5, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 3));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 6, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 4));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_2, 7, bitRead(Pt_Veh_1_Val->Pt_tAmbEdrv, 5));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 0, bitRead(Pt_Veh_1_Val->Pt_vVeh, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 1, bitRead(Pt_Veh_1_Val->Pt_vVeh, 3));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 2, bitRead(Pt_Veh_1_Val->Pt_vVeh, 4));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 3, bitRead(Pt_Veh_1_Val->Pt_vVeh, 5));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 4, bitRead(Pt_Veh_1_Val->Pt_vVeh, 6));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 5, bitRead(Pt_Veh_1_Val->Pt_vVeh, 7));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 6, bitRead(Pt_Veh_1_Val->Pt_vVeh, 8));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_3, 7, bitRead(Pt_Veh_1_Val->Pt_vVeh, 9));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 0, bitRead(Pt_Veh_1_Val->Pt_nEng, 8));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 1, bitRead(Pt_Veh_1_Val->Pt_nEng, 9));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 2, bitRead(Pt_Veh_1_Val->Pt_nEng, 10));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 3, bitRead(Pt_Veh_1_Val->Pt_nEng, 11));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 4, bitRead(Pt_Veh_1_Val->Pt_nEng, 12));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 5, bitRead(Pt_Veh_1_Val->Pt_nEng, 13));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 6, bitRead(Pt_Veh_1_Val->Pt_vVeh, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_4, 7, bitRead(Pt_Veh_1_Val->Pt_vVeh, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 0, bitRead(Pt_Veh_1_Val->Pt_nEng, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 1, bitRead(Pt_Veh_1_Val->Pt_nEng, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 2, bitRead(Pt_Veh_1_Val->Pt_nEng, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 3, bitRead(Pt_Veh_1_Val->Pt_nEng, 3));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 4, bitRead(Pt_Veh_1_Val->Pt_nEng, 4));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 5, bitRead(Pt_Veh_1_Val->Pt_nEng, 5));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 6, bitRead(Pt_Veh_1_Val->Pt_nEng, 6));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_5, 7, bitRead(Pt_Veh_1_Val->Pt_nEng, 7));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 0, bitRead(Pt_Veh_1_Val->Pt_nrAlvCntrIgn, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 1, bitRead(Pt_Veh_1_Val->Pt_nrAlvCntrIgn, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 2, bitRead(Pt_Veh_1_Val->Pt_nrAlvCntrIgn, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 3, bitRead(Pt_Veh_1_Val->Pt_nrAlvCntrIgn, 3));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 4, bitRead(Pt_Veh_1_Val->Pt_stIgnSwt, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 5, bitRead(Pt_Veh_1_Val->Pt_stIgnSwt, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 6, bitRead(Pt_Veh_1_Val->Pt_stIgnSwt, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_6, 7, 0);
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 0, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 0));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 1, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 1));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 2, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 2));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 3, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 3));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 4, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 4));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 5, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 5));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 6, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 6));
  bitWrite(Pt_Veh_1_Data->Pt_Veh_1_7, 7, bitRead(Pt_Veh_1_Val->Pt_nrChksIgn, 7)); 
}


typedef struct
{
  uint16_t Edrv_Act_1_0 = 0x00;
  uint16_t Edrv_Act_1_1 = 0x00;
  uint16_t Edrv_Act_1_2 = 0x00;
  uint16_t Edrv_Act_1_3 = 0x00;
  uint16_t Edrv_Act_1_4 = 0x00;
  uint16_t Edrv_Act_1_5 = 0x00;
  uint16_t Edrv_Act_1_6 = 0x00;
  uint16_t Edrv_Act_1_7 = 0x00;
} Edrv_Act_1_Data;

typedef struct
{
  uint16_t Edrv_nrChksAct_Val = 0x00;
  uint16_t Edrv_nrAlvCntrAct_Val = 0x00;
  uint16_t Edrv_stRunAct_Val = 0x00;
  uint16_t Edrv_stOperModAct_Val = 0x00;
  uint16_t Edrv_tqAct_Val = 0x00;
  uint16_t Edrv_nAct_Val = 0x00;
  uint16_t Edrv_uAct_Val = 0x00;
  uint16_t Edrv_iAct_Val = 0x00;
} Edrv_Act_1_Val;

int Edrv_nrChksAct = 0x00;
int Edrv_nrAlvCntrAct = 0x00;
int Edrv_stRunAct = 0x00;
int Edrv_stOperModAct = 0x00;
float Edrv_tqAct = 0x00;
int Edrv_nAct = 0x00;
float Edrv_uAct = 0x00;
int Edrv_iAct = 0x00;


void atualizaRX_Edrv_Act_1(Edrv_Act_1_Val *Edrv_Act_1_Val, Edrv_Act_1_Data *Edrv_Act_1_Data)
{
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 0));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 1));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 4, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 2));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 5, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 3));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 6, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 4));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 7, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 5));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 8, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 6));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 9, bitRead(Edrv_Act_1_Data->Edrv_Act_1_0, 7));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 4, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 0));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 5, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 1));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 6, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 2));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 7, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 3));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 8, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 4));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 9, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 5));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 6));
bitWrite(Edrv_Act_1_Val->Edrv_iAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_1, 7));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 10, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 0));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 11, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 1));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 12, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 2));

bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 4));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 5));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 6));
bitWrite(Edrv_Act_1_Val->Edrv_uAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_2, 7));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 0));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 1));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 4, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 2));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 5, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 3));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 6, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 4));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 7, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 5));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 8, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 6));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 9, bitRead(Edrv_Act_1_Data->Edrv_Act_1_3, 7));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 6, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 0));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 7, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 1));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 8, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 2));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 9, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 3));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 10, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 4));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 11, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 5));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 6));
bitWrite(Edrv_Act_1_Val->Edrv_nAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_4, 7));
bitWrite(Edrv_Act_1_Val->Edrv_stOperModAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 0));
bitWrite(Edrv_Act_1_Val->Edrv_stOperModAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 1));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 2));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 3));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 4));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 5));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 4, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 6));
bitWrite(Edrv_Act_1_Val->Edrv_tqAct_Val, 5, bitRead(Edrv_Act_1_Data->Edrv_Act_1_5, 7));
bitWrite(Edrv_Act_1_Val->Edrv_nrAlvCntrAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 0));
bitWrite(Edrv_Act_1_Val->Edrv_nrAlvCntrAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 1));
bitWrite(Edrv_Act_1_Val->Edrv_nrAlvCntrAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 2));
bitWrite(Edrv_Act_1_Val->Edrv_nrAlvCntrAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 3));
bitWrite(Edrv_Act_1_Val->Edrv_stRunAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 4));
bitWrite(Edrv_Act_1_Val->Edrv_stRunAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 5));
bitWrite(Edrv_Act_1_Val->Edrv_stOperModAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 6));
bitWrite(Edrv_Act_1_Val->Edrv_stOperModAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_6, 7));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 0, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 0));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 1, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 1));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 2, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 2));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 3, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 3));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 4, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 4));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 5, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 5));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 6, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 6));
bitWrite(Edrv_Act_1_Val->Edrv_nrChksAct_Val, 7, bitRead(Edrv_Act_1_Data->Edrv_Act_1_7, 7));
}
