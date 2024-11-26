int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 15; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);                
    digitalWrite(ledPin, LOW); 
    delay(500);    
  }
  while (true) {
    // Gjør ingenting, stopper programmet
  }
}
