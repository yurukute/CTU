const int green = 10;
const int yellow = 11;
const int red = 12;
const int delayTime = 5000;
const int lights[] = { green, yellow, red };

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(lights[i], OUTPUT);
    digitalWrite(lights[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    printStatus(i);
    switchLight(i);
    if (lights[i] != yellow)
      delay(delayTime);
    else
      delay(delayTime - 300);
  }
}

void switchLight(int x) {
  for (int i = 0; i < 3; i++) {
    if (i == x)
      digitalWrite(lights[i], HIGH);
    else
      digitalWrite(lights[i], LOW);
  }
}

void printStatus(int x) {
  char* lights[] = { "Green", "Yellow", "Red" };
  Serial.println((String) "Advanced " + lights[x]);
  for (int i = 0; i < 3; i++) {
    Serial.print((String)lights[i] + "\t: ");
    if (i == x)
      Serial.println("on");
    else
      Serial.println("off");
  }
}
