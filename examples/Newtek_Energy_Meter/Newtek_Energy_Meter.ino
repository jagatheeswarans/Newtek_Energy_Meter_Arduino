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

#include <Newtek_Energy_Meter.h>

Energy_Meter energy;
void setup() {
  
    Serial.begin(9600); //BaudRate of the ModBus Communication
    
}

void loop() {
    /*Repeatedly fetch some values from the EnergyMeter */

  Serial.print("Voltage:");
  Serial.println(energy.GetLineVoltage());
  delay(100);
  Serial.print("Current:");
  Serial.println(energy.GetLineCurrent());
  delay(100);
  Serial.print("Power:");
  Serial.println(energy.GetPower());
  delay(100);
  Serial.print("PowerFactor:");
  Serial.println(energy.GetPowerFactor());
  delay(100);
  Serial.print("Frequency:");
  Serial.println(energy.GetFrequency());
  delay(100);
  Serial.print("Energy:");
  Serial.println(energy.GetImportEnergy());
  delay(100);
  
}
