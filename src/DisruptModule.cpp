#include "DisruptModule.h"

void DisruptSetup()
{
    pinMode(interruptPin, INPUT_PULLUP);                                             // the button pin is set to input pull-up mode
    attachInterrupt(digitalPinToInterrupt(interruptPin), AdjustResolution, FALLING); // xternal interrupt touch type is falling edge; adjust_resolution is interrupt service function ISR
}

void AdjustResolution()
{
    tone(buzzer, 800, 100);
    delay(10); // delay to eliminate vibration
    if (!digitalRead(interruptPin))
    {
        if (resolution < 5)
        {
            resolution++;
        }
        else
        {
            resolution = 1;
        }
    }
}