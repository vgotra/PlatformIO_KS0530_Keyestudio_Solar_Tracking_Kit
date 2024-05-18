#include "DisplayModule.h"
#include "LightMeterModule.h"
#include "ServoModule.h"
#include "DhtModule.h"
#include "DisruptModule.h"

// common variables
int temperature;     // save the variable of temperature
int humidity;        // save the variable of humidity
unsigned int light;  // save the variable of light intensity
byte resolution = 1; // move this to common header file

// BH1750 light meter
BH1750 lightMeter;

// dht11
dht11 DHT;         // TODO Check are we need to use this variable in this file
int DHT11_PIN = 7; // define the DHT11 as the digital pin 7

// lcd display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Configuration of Servo motors
Servo lr_servo;
Servo ud_servo;
const byte lr_servopin = 9;
const byte ud_servopin = 10;
int lr_angle = 90;
int ud_angle = 10;
int l_state = A0;
int r_state = A1;
int u_state = A2;
int d_state = A3;
byte error = 15;
byte m_speed = 10;

// disrupt
const byte interruptPin = 2; // the pin of button;the corruption is disrupted
const byte buzzer = 6;       // set the pin of the buzzer to digital pin 6

void setup()
{
  LcdSetup();
  LightMeterSetup();
  ServoSetup();
  DisruptSetup();
}

void loop()
{
  ServoAction();    // servo performs the action
  LightMeterRead(); // read the value of light intensity
  DhtRead();        // read the value of temperature and humidity
  LcdShowValue();   // Lcd shows the values of light intensity, temperature and humidity
}