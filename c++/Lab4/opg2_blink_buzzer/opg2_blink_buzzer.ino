const int led = 5; 
const int buzzer = 2; 

void controlLED(int delayTime) {
  digitalWrite(buzzer, LOW); 
  digitalWrite(led, HIGH); 
  delay(delayTime); 
  digitalWrite(led, LOW); 
  delay(delayTime); 
}

void controlBuzzer(int frequency) {
  digitalWrite(led, LOW);
  tone(buzzer, frequency);
  delay(1000);
  noTone(buzzer); 
}
void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available() > 0) {
    int valg = Serial.parseInt(); 
    int delayTime = Serial.parseInt(); 

    if (valg == 1) {
      controlLED(delayTime); 
    } else if (valg == 2) {
      controlBuzzer(delayTime); 
    }
  }
}


