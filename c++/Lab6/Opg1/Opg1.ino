const int knapp1 = 3;
const int led = 10;

const int debounce_time = 200;
unsigned long last_interrupt = 0;

int blink_interval = 1000;

void setup() {
  pinMode(knapp1, INPUT);
  pinMode(led, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(knapp1), raskere, FALLING);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(blink_interval);
  digitalWrite(led, LOW);
  delay(blink_interval);
}

void raskere() {
  if (millis() > last_interrupt + debounce_time) {
    blink_interval = max(100, blink_interval - 100);

    Serial.print("Nytt blinkintervall: ");
    Serial.println(blink_interval);

    last_interrupt = millis();
  }
}