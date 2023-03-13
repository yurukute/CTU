#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Hello World");
}

void loop(){
  if(Serial.available()){
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(Serial.readString());
  }
}
