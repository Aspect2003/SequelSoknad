int ledPin = 3;
int buttonPin = 7;
int potmeter = A0;
const int interval = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  static unsigned long lastChange = 0;
  static bool ledState = LOW;
  int knappStatus = digitalRead(buttonPin);
  int potVerdi = analogRead(potmeter);
  int interval = map(potVerdi, 0, 1023, 0, 10000);

  if (knappStatus == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
  if (millis() >= lastChange + interval) {
    ledState = !ledState;
    lastChange = millis();
  }
  digitalWrite(ledPin, ledState);
  }
}


