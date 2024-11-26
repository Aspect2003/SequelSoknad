int knapp = 3;
int led = 5;


void setup() {
pinMode(led, OUTPUT);
pinMode(knapp, INPUT);
}


void loop() {
int buttonState = digitalRead(knapp);  // Les tilstanden til knappen

  if (buttonState == HIGH) {  // Hvis knappen er trykket inn
    digitalWrite(led, HIGH);  // Slå på LED
  } else {  // Hvis knappen ikke er trykket inn
    digitalWrite(led, LOW);  // Slå av LED
  }
}


