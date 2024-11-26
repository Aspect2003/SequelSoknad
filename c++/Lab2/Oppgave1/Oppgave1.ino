const int ledPin = 13;
const int buttonPin1 = 2;
const int buttonPin2 = 3; 

void setup() {
  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT); 
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1); 
  int buttonState2 = digitalRead(buttonPin2); 

  if (buttonState1 == HIGH && buttonState2 == HIGH) {
    digitalWrite(ledPin, HIGH); // Begge knappene er trykket inn, LED lyser
  } else if (buttonState1 == HIGH || buttonState2 == HIGH) {
    blinkLED(); // En av knappene er trykket inn, LED blinker
  } else {
    digitalWrite(ledPin, LOW); // Ingen knapper er trykket inn, LED er slukket
  }
}

void blinkLED() {
  digitalWrite(ledPin, HIGH); 
  delay(500); 
  digitalWrite(ledPin, LOW); 
  delay(500); 
