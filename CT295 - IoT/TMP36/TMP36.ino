const int tmp = A0;
float Vin = 5;

void setup() {
	Serial.begin(9600);
}

void loop() {
	float miliVolt = analogRead(tmp)*Vin/1024;
  float temp = (miliVolt - 0.5)*100;
	Serial.println((String)"Temp: " + temp + "°C");
	delay(5000);
}