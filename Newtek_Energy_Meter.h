#ifndef Energy_Meter_h
#define Energy_Meter_h
#include "Arduino.h"

class Energy_Meter {
  private:
    float CommEnergy(byte a,byte b,byte c,byte d,byte e,byte f,byte g,byte h);
    
  public:
    float GetLineVoltage();
    float GetLineCurrent();
    float GetFrequency();
    float GetPowerFactor();
    float GetPower();
    float GetImportEnergy();
    float GetAppEnergy();

};


#endif
