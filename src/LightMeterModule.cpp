#include "LightMeterModule.h"

void LightMeterSetup()
{
    // Initialize the I2C bus (BH1750 library doesn't do this automatically)
  Wire.begin();
  lightMeter.begin();
}

void LightMeterRead()
{
    light = lightMeter.readLightLevel(); // read the light intensity detected by BH1750
}