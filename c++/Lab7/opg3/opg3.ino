const int redPin = 11;     
const int greenPin = 10;  
const int bluePin = 9;     
const int buttonPin1 = 2;  
const int buttonPin2 = 3;  
const int buttonPin3 = 18;
const int potPin = A0;     

enum possibleStates { on, blink, off, emergencystop };
const int numberOfStates = 3; // Ekskluderer emergencystop
possibleStates state = on;

enum lightStates { GREEN, BLUE, RED };
lightStates currentLightState = GREEN;

const int interval = 600;

unsigned long lastChange = 0;
bool ledState = HIGH;

// Debounce variabler
unsigned long lastButtonPressTime1 = 0;
unsigned long lastButtonPressTime2 = 0;
const unsigned long debounceTime = 200;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin1), changeStateForward, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), changeStateBackward, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin3), activateEmergencyStop, FALLING);
  Serial.begin(9600);
}

void loop() {
  static unsigned long lastOutputTime = 0;
  if (millis() - lastOutputTime >= 200) {
    Serial.println(state);
    lastOutputTime = millis();
  }

  int potValue = analogRead(potPin);

  // Oppdatere lys tilstand basert på potmeter verdi og diagram
  switch (currentLightState) {
    case GREEN:
      if (potValue > 300) {
        currentLightState = BLUE;
      }
      break;
    case BLUE:
      if (potValue < 250) {
        currentLightState = GREEN;
      } else if (potValue > 850) {
        currentLightState = RED;
      }
      break;
    case RED:
      if (potValue < 750) {
        currentLightState = BLUE;
      }
      break;
  }

  // Oppdatere LED basert på gjeldende tilstand
  switch (state) {
    case on:
      switch (currentLightState) {
        case GREEN:
          analogWrite(greenPin, 255);
          analogWrite(redPin, 0);
          analogWrite(bluePin, 0);
          break;
        case BLUE:
          analogWrite(greenPin, 0);
          analogWrite(redPin, 0);
          analogWrite(bluePin, 255);
          break;
        case RED:
          analogWrite(greenPin, 0);
          analogWrite(redPin, 255);
          analogWrite(bluePin, 0);
          break;
      }
      break;
    case blink:
      if (millis() >= lastChange + interval) {
        ledState = !ledState;
        lastChange = millis();
      }
      if (ledState) {
        switch (currentLightState) {
          case GREEN:
            analogWrite(greenPin, 255);
            analogWrite(redPin, 0);
            analogWrite(bluePin, 0);
            break;
          case BLUE:
            analogWrite(greenPin, 0);
            analogWrite(redPin, 0);
            analogWrite(bluePin, 255);
            break;
          case RED:
            analogWrite(greenPin, 0);
            analogWrite(redPin, 255);
            analogWrite(bluePin, 0);
            break;
        }
      } else {
        analogWrite(greenPin, 0);
        analogWrite(redPin, 0);
        analogWrite(bluePin, 0);
      }
      break;
    case off:
    case emergencystop:
      analogWrite(greenPin, 0);
      analogWrite(redPin, 0);
      analogWrite(bluePin, 0);
      break;
    default:
      Serial.println("Ugyldig tilstand");
  }
}

void changeStateForward() {
  unsigned long currentTime = millis();
  if (currentTime - lastButtonPressTime1 >= debounceTime && state != emergencystop) {
    lastButtonPressTime1 = currentTime;
    state = static_cast<possibleStates>((state + 1) % numberOfStates);
    Serial.println("Tilstand endret fremover");
  }
}

void changeStateBackward() {
  unsigned long currentTime = millis();
  if (currentTime - lastButtonPressTime2 >= debounceTime && state != emergencystop) {
    lastButtonPressTime2 = currentTime;
    if (state == 0) {
      state = static_cast<possibleStates>(numberOfStates - 1);
    } else {
      state = static_cast<possibleStates>(state - 1);
    }
    Serial.println("Tilstand endret bakover");
  }
}

void activateEmergencyStop() {
  state = emergencystop;
  Serial.println("Nødstop aktivert");
}
