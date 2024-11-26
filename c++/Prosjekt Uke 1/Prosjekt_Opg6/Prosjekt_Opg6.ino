int LED_1 = 11;
int LED_2 = 3;
int knapp_1 = 12;
int knapp_2 = 2;
int buzzer = 8;

int minDelay = 500;
int maxDelay = 6000;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(knapp_1, INPUT);
  pinMode(knapp_2, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 1000);
  delay(random(minDelay, maxDelay));
  noTone(buzzer);

  while (true) {
    int knapp_1_status = digitalRead(knapp_1);
    int knapp_2_status = digitalRead(knapp_2);

    if (knapp_1_status == HIGH) {
      digitalWrite(LED_1, HIGH);
      delay(1000);
      digitalWrite(LED_1, LOW);
      break;
    } else if (knapp_2_status == HIGH) {
      digitalWrite(LED_2, HIGH);
      delay(1000);
      digitalWrite(LED_2, LOW);
      break;
    }
  }

  delay(1000);
}
