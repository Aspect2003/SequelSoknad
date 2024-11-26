//oppgave 3
int ledPin =8;
int delayTime = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (delayTime <= 5000) {
    digitalWrite(ledPin, HIGH);
    delay(delayTime);
    digitalWrite(ledPin, LOW);
    delay(delayTime);
    delayTime += 10;
  }
  delayTime = 10;
}