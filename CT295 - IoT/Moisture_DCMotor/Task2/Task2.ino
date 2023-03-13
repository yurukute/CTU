#include <LiquidCrystal.h>

#define moistPin A0
#define temptPin A1
#define motorPin 6

LiquidCrystal lcd(3, 5, 9, 10, 11, 12);
float Vin = 5;
float volume;
float moisture;
float miliVolt;
float tempt;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(motorPin, OUTPUT);
}

void loop(){
  readSensors();
  lcdPrint();
  delay(2000);
}

void readSensors(){
  volume = analogRead(moistPin);
  moisture = (volume/1023)*100;
  
  miliVolt = analogRead(temptPin)*Vin/1024;
  tempt = (miliVolt - 0.5)*100;
}

void serialPrint(){
  Serial.println((String)"Moist: " + moisture + "rH");
  Serial.println((String)"Tempt: " + tempt + char(176) + "C");
}

void lcdPrint(){
  lcd.clear();  
  lcd.print((String)"Moist: " + moisture + "rH");
  lcd.setCursor(0,1);
  lcd.print((String)"Tempt: " + tempt + char(223) + "C");
}