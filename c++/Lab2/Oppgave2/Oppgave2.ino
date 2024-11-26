int buzzer = 8;
int knapp1 = 4;
int knapp2 = 7;

void setup() {
pinMode(buzzer, OUTPUT);
pinMode(knapp1, INPUT);
pinMode(knapp2, INPUT);
Serial.begin(9600);
}

void loop() {
int knapp1status = digitalRead(knapp1);
int knapp2status = digitalRead(knapp2);

if (knapp1status == HIGH) {
  Serial.print(".");
  tone(buzzer, 1000);
  delay(200);
  noTone(buzzer);
}

if (knapp2status == HIGH) {
  Serial.print("-");
  tone(buzzer, 1000);
  delay(400);
  noTone(buzzer);
}
}