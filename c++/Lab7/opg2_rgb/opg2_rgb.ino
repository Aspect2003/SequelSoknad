const int potPin = A0;     
const int redPin = 11;      
const int greenPin = 10;   
const int bluePin = 9;    

enum State {GREEN, BLUE, RED};
State currentState = GREEN;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  switch (currentState) {
    case GREEN:
      analogWrite(greenPin, 255);
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      if (potValue > 300) {
        currentState = BLUE;
      }
      break;
      
    case BLUE:
      analogWrite(greenPin, 0);
      analogWrite(redPin, 0);
      analogWrite(bluePin, 255);
      if (potValue < 250) {
        currentState = GREEN;
      } else if (potValue > 850) {
        currentState = RED;
      }
      break;
      
    case RED:
      analogWrite(greenPin, 0);
      analogWrite(redPin, 255);
      analogWrite(bluePin, 0);
      if (potValue < 750) {
        currentState = BLUE;
      }
      break;
  }

  delay(200);  // Liten forsinkelse for stabilitet
}
