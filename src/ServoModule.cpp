#include "ServoModule.h"

void ServoSetup()
{
  lr_servo.attach(lr_servopin); // set the control pin of servo
  ud_servo.attach(ud_servopin); // set the control pin of servo
  pinMode(l_state, INPUT);      // set the mode of pin
  pinMode(r_state, INPUT);
  pinMode(u_state, INPUT);
  pinMode(d_state, INPUT);

  lr_servo.write(lr_angle); // return to initial angle
  delay(1000);
  ud_servo.write(ud_angle);
  delay(1000);
}

void ServoAction()
{
  int L = analogRead(l_state); // read the analog voltage value of the sensor, 0-1023
  int R = analogRead(r_state);
  int U = analogRead(u_state);
  int D = analogRead(d_state);

  /**********************system adjusting left and right序**********************/
  if (abs(L - R) > error && L > R)
  {                         // Determine whether the error is within the acceptable range, otherwise adjust the steering gear
    lr_angle -= resolution; // reduce the angle
    if (lr_angle < 0)
    { // limit the rotation angle of the servo
      lr_angle = 0;
    }
    lr_servo.write(lr_angle); // output the angle of the servooutput the angle of servo
    delay(m_speed);
  }
  else if (abs(L - R) > error && L < R)
  {                         // Determine whether the error is within the acceptable range, otherwise adjust the steering gear
    lr_angle += resolution; // increase the angle
    if (lr_angle > 180)
    { // limit the rotation angle of servo
      lr_angle = 180;
    }
    lr_servo.write(lr_angle); // output the angle of servo
    delay(m_speed);
  }
  else if (abs(L - R) <= error)
  {                           // Determine whether the error is within the acceptable range, otherwise adjust the steering gear
    lr_servo.write(lr_angle); // output the angle of servo
  }

  /**********************system adjusting up and down**********************/
  if (abs(U - D) > error && U >= D)
  {                         // Determine whether the error is within the acceptable range, otherwise adjust the steering gear
    ud_angle -= resolution; // reduce the angle
    if (ud_angle < 10)
    { // limit the rotation angle of servo
      ud_angle = 10;
    }
    ud_servo.write(ud_angle); // output the angle of servo
    delay(m_speed);
  }
  else if (abs(U - D) > error && U < D)
  {                         // Determine whether the error is within the acceptable range, otherwise adjust the steering gear
    ud_angle += resolution; // increase the angle
    if (ud_angle > 90)
    { // limit the rotation angle of servo
      ud_angle = 90;
    }
    ud_servo.write(ud_angle); // output the angle of servo
    delay(m_speed);
  }
  else if (abs(U - D) <= error)
  {                           // Determine whether the error is within the acceptable range. If it is, keep it stable and make no change in angle
    ud_servo.write(ud_angle); // output the angle of servo
  }
}
