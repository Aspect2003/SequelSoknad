int knapp1 = 8;
int knapp2 = 10;
int ledPin = 3;
int buzzer = 31;

int status = 0;  // status på lås

void setup() {
  pinMode(knapp1, INPUT);
  pinMode(knapp2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(knapp1) == HIGH) {
    status = 1;
    delay(500);
  }

  if (status == 1 && digitalRead(knapp2) == HIGH) {
    digitalWrite(ledPin, HIGH);  // riktig kode
    delay(500);
  } else if (status == 0 && digitalRead(knapp2) == HIGH) {
    tone(buzzer, 1000);  // feil kode
    delay(1000);
    noTone(buzzer);
    status = 0;  //resetter
  }
}