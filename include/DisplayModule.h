#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include <Arduino.h>
#include "KS0530Common.h"
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

void LcdSetup();
void LcdShowValue();

#endif // DISPLAYMODULE_H