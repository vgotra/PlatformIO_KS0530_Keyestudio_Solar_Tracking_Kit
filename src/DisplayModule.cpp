#include "DisplayModule.h"

void LcdSetup()
{
  lcd.init(); // initialize the LCD
  lcd.backlight(); //set LCD backlight
  lcd.setCursor(0, 0);
  lcd.print("Started");
}

void LcdShowValue() {
  char str1[5];
  char str2[2];
  char str3[2];
  dtostrf(light, -5, 0, str1); //Format the light value data as a string, left-aligned
  dtostrf(temperature, -2, 0, str2);
  dtostrf(humidity, -2, 0, str3);
  //LCD1602 display
  //display the value of the light intensity
  lcd.setCursor(0, 0);
  lcd.print("Light:");
  lcd.setCursor(6, 0);
  lcd.print(str1);
  lcd.setCursor(11, 0);
  lcd.print("lux");

  //display the value of temperature and humidity
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.setCursor(2, 1);
  lcd.print("C");
  lcd.setCursor(5, 1);
  lcd.print(humidity);
  lcd.setCursor(7, 1);
  lcd.print("%");

  //show the accuracy of rotation
  lcd.setCursor(11, 1);
  lcd.print("res:");
  lcd.setCursor(15, 1);
  lcd.print(resolution);
}