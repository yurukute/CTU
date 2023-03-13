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
  dcMotor(moisture, 50);
  dcMotor(tempt, 30);
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
  lcd.print((String)moisture + "rH");
  //lcd.setCursor(0,1);
  lcd.setCursor(8,0);
  lcd.print((String)tempt + char(223) + "C");
}

void dcMotor(float value, float range){
  lcd.setCursor(0,1);
  if(value <= range){
    digitalWrite(motorPin, LOW);
    lcd.print("Motor: OFF");
  }
  else {
    digitalWrite(motorPin, HIGH);
    lcd.print("Motor: ON ");
  }
}