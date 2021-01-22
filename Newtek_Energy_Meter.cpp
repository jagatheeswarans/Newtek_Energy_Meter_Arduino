/*
Energy meter code writteny by Jagatheeswaran Senthilvelan
method:ASCII modbus(hex frame will reach newtek in the form of equivalent ascii characters).Use printf(%c,variable[i]) with for loop in case ANSI C coding.
RS485 tx should connect to rx & RS485 rx to tx of arduio.
Use siliconlabz module or nsk(maxim integrated) module for communication.
Newtek frames for single phase
  byte Voltage[] ={0x01,0x04,0x00,0x00,0x00,0x02,0x71,0xCB};//byte array to read voltage value from meter
  byte Current[] ={0x01,0x04,0x00,0x06,0x00,0x02,0x91,0xCA};
  byte Power[] ={0x01,0x04,0x00,0x06,0x00,0x46,0x71,0xF8};
  byte Frequency[] ={0x01,0x04,0x00,0x46,0x00,0x02,0x90,0x1E};
  byte PF[] ={0x01,0x04,0x00,0x40,0x00,0x02,0x70,0x1F};
  byte KWh[] ={0x01,0x04,0x00,0x44,0x00,0x02,0x71,0xD5};  
Use char KWh[] in case of ANSI C
*/

/*************************** Energy Meter Variables ************************************/
#include "Newtek_Energy_Meter.h"

byte byte_array[4];
byte incoming[9]={0};

/*************************** Bytes to Float Conversion ************************************/

union  
  {
   byte b[4];
   float f;
   } data;

/*************************** Data Communicaton ************************************/

float Energy_Meter :: CommEnergy(byte a,byte b,byte c,byte d,byte e,byte f,byte g,byte h)
{
  int i=0;
  byte frame[] ={a,b,c,d,e,f,g,h};  
  Serial.write(frame,sizeof(frame));  delay(50);   
  int z=Serial.available();//number of bytes 
  
 while (Serial.available() > 0)
  {incoming[i] =  Serial.read();i++;}delay(50);  
  int  j=0;
  for(int i=6;i>=3;i--){byte_array[j]=incoming[i];j++;}//here data got is reversed because we must send MSB first and then LSB       

  for(int i=0;i<=3;i++){data.b[i]=byte_array[i];}
  
  float ieee=data.f;delay(1000);
  return(ieee);
}

float Energy_Meter :: GetLineVoltage()
  {
    float V = CommEnergy(0x01,0x04,0x00,0x00,0x00,0x02,0x71,0xCB);
    return (V);
  }

float Energy_Meter :: GetLineCurrent()
  {
    float I = CommEnergy(0x01,0x04,0x00,0x06,0x00,0x02,0x91,0xCA);
    return (I);
  }

float Energy_Meter :: GetFrequency()
  {
    float F = CommEnergy(0x01,0x04,0x00,0x46,0x00,0x02,0x90,0x1E);
    return (F);
  }

float Energy_Meter :: GetPowerFactor()
  {
    float PF = CommEnergy(0x01,0x04,0x00,0x40,0x00,0x02,0x70,0x1F);
    return (PF);
  }

float Energy_Meter :: GetPower()
  {
    float P = CommEnergy(0x01,0x04,0x00,0x0C,0x00,0x02,0xB1,0xC8);
    return (P);
  }
  
float Energy_Meter :: GetImportEnergy()
  {
    float Wh = CommEnergy(0x01,0x04,0x00,0x5E,0x00,0x02,0x10,0x19);
    return (Wh);
  }

float Energy_Meter :: GetAppEnergy()
  {
    float VAh = CommEnergy(0x01,0x04,0x00,0x66,0x00,0x02,0x91,0xD4);
    return (VAh);
  }
