// Variabler
int blue = 7;
int yellow = 5;
int red = 3;
int pot = A0;

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  int potVerdi = analogRead(pot);
  int delayTid = max(potVerdi * 6, 20);
  int langDelayTid = delayTid * 3;

  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(langDelayTid);

  digitalWrite(yellow, HIGH);
  delay(delayTid);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(blue, HIGH);
  delay(langDelayTid);

  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(delayTid);
}
