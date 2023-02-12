int mode = 0;
int leds[] = {2, 3, 4, 5, 6};
int n = 5;
void setup() {
  for (int i = 0; i < n; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();
    if (input == 'h')
      printHelp();
    else if (input >= '1' && input <= '4')
      switchMode(input - '1');
    else
      Serial.println("Error: input 1-4 only. Type `h` for instruction.");
  }
  switch (mode) {
    case 1:
      blinking(300);
      break;
    case 2:
      switching(300);
      break;
    case 3:
      chasing(200); 
      break;
    case 4:
      combination();
      break;
  }
}

void printHelp() {
  Serial.println("Christmas light control, version 1.0. "
  "Type `h` to see this list.\n"
  "Type 1-4 to change mode light:\n"
  " 1. Blinking\n"
  " 2. Switching\n"
  " 3. \n"
  " 4. Combination");
}

void switchMode(int i) {
  char* modes[] = { "Blinking", "Switching", "Chasing", "Combination" };
  Serial.print(modes[i++]);
  Serial.println(" mode on.");
  mode = i;
}

void blinking(int delayTime) {
  for (int i = 0; i < n; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(delayTime);
  for (int i = 0; i < n; i++) {
    digitalWrite(leds[i], LOW);
  }
  delay(delayTime);
}

void switching(int delayTime) {
  for (int i = 0; i < n; i++) {
    digitalWrite(leds[i], i % 2);
  }
  delay(delayTime);
  for (int i = 0; i < n; i++) {
    digitalWrite(leds[i], (i + 1) % 2);
  }
  delay(delayTime);
}

void chasing(int delayTime){
  for(int i = 0; i < n; i++){
    digitalWrite(leds[i], HIGH);
    delay(delayTime);
    digitalWrite(leds[i], LOW);
  }
}

void combination() {
  for(int i = 0; i < 7; i++){
    if(i < 2)
      blinking(200);
    else if (i < 6)
      switching(200);
    else {
      chasing(300);
      chasing(100);
    }
  }
}
