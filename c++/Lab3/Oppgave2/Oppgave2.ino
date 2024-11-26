int ledPin = 3;
int buttonPin = 7;
const int interval = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  static unsigned long lastChange = 0;
  static bool ledState = LOW;
  int knappStatus = digitalRead(buttonPin);

  if (knappStatus == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
  if (millis() >= lastChange + interval) {
    ledState = !ledState;
    lastChange = millis();
    delay(500);
  }
  digitalWrite(ledPin, ledState);
  }
}


