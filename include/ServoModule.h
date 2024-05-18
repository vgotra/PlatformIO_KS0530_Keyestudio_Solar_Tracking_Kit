#ifndef SERVOMODULE_H
#define SERVOMODULE_H

#include <Arduino.h>
#include "KS0530Common.h"
#include <Servo.h>

extern Servo lr_servo;//define the name of the servo rotating right and left
extern Servo ud_servo;//efine the name of the servo rotating upwards and downwards

extern const byte lr_servopin; //define the control signal pin of the servo rotating right and lef
extern const byte ud_servopin; //define the control signal pin of the servo rotating clockwise and anticlockwise

extern int lr_angle; // The initial angle of the servo motor. The initial angle is 90 degrees, which is the middle position of the servo motor
extern int ud_angle; // The initial angle of the servo motor. The initial angle is 10 degrees, which is the minimal position of the servo motor

// photoresistor analog pins
extern int l_state;
extern int r_state;
extern int u_state;
extern int d_state;

extern byte error;
extern byte m_speed; //set delay time to adjust the speed of servo;the longer the time, the smaller the speed

void ServoSetup();
void ServoAction();

#endif // SERVOMODULE_H