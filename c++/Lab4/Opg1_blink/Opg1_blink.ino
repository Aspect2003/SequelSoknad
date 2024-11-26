int led = 5;

void blink(int forsinkelse) {
  digitalWrite(led, HIGH);
  delay(forsinkelse);
  digitalWrite(led, LOW);
  delay(forsinkelse);
}

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int forsinkelse = Serial.parseInt();
    blink(forsinkelse);
  }
}
