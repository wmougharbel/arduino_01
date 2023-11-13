#include <LiquidCrystal.h>

const int analogPin = A0;
const int ledPin = 10;
const int rs = 11, en = 2, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
int brightness = 0;
int sensor_val = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("BRIGHTNESS:");
}

void loop()
{
  lcd.setCursor(0,1);
  sensor_val = analogRead(analogPin);
  brightness = map(sensor_val, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  lcd.print(sensor_val);
  lcd.print("    ");
}

// issue when we are getting four digits; then the last one remains