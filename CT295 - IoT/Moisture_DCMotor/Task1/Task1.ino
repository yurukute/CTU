#define moistPin A0
#define temptPin A1

float Vin = 5;
float volume;
float moisture;
float miliVolt;
float tempt;

void setup(){
  Serial.begin(9600);
}

void loop(){
  readSensors();
  serialPrint();
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