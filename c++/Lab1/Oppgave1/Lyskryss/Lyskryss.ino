// Variabler
int blue = 7;
int yellow = 5;
int red = 3;

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

}

void loop() {
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(2000);

  digitalWrite(yellow, HIGH);
  delay(2000);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(blue, HIGH);
  delay(2000);

  digitalWrite(blue, LOW);
  digitalWrite(yellow, HIGH);
  delay(2000);
} 