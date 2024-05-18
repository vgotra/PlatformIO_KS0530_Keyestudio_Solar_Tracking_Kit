#ifndef LIGHTMETERMODULE_H
#define LIGHTMETERMODULE_H

#include <Arduino.h>
#include <Wire.h>
#include "KS0530Common.h"
#include <BH1750.h>

extern BH1750 lightMeter;

void LightMeterSetup();
void LightMeterRead();

#endif // LIGHTMETERMODULE_H
