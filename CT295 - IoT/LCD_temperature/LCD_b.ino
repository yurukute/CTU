#include <LiquidCrystal.h>

const int tmp = A5
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){
  float voltage = analogRead(tmp) * (5.0 / 1024.0);
  float celsius = (voltage - 0.5) * 100;
  float fahrenheit = ((celsius * 1.8)+32);

  lcd.clear();
  lcd.print((String)celsius+(char)223+"C");
  lcd.setCursor(0,1);
  lcd.print((String)fahrenheit+(char)223+"F");

  delay(2000);
}