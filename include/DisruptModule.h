#ifndef DISRUPTMODULE_H
#define DISRUPTMODULE_H

#include <Arduino.h>
#include "KS0530Common.h"

extern const byte interruptPin; // the pin of button;the corruption is disrupted
extern const byte buzzer;       // set the pin of the buzzer to digital pin 6

void DisruptSetup();
void AdjustResolution();

#endif // DISRUPTMODULE