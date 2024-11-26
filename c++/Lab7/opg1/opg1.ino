const int ledPin = 7;
const int buttonPin1 = 2; // Knapp for å endre tilstand fremover
const int buttonPin2 = 3; // Knapp for å endre tilstand bakover
const int buttonPin3 = 18; // Knapp for nødstop

enum possibleStates { on, blink, off, emergencystop };
const int numberOfStates = 3; // Ekskluderer emergencystop
possibleStates state = on;

const int interval = 600;

unsigned long lastChange = 0;
bool ledState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
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
  
  switch (state) {
    case on:
      ledState = HIGH;
      break;
    case blink:
      if (millis() >= lastChange + interval) {
        ledState = !ledState;
        lastChange = millis();
      }
      break;
    case off:
    case emergencystop:
      ledState = LOW;
      break;
    default:
      Serial.println("Ugyldig tilstand");
  }
  digitalWrite(ledPin, ledState);
}

void changeStateForward() {
  static unsigned long lastButtonPressTime1 = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastButtonPressTime1 >= 200 && state != emergencystop) {
    lastButtonPressTime1 = currentTime;
    state = static_cast<possibleStates>((state + 1) % numberOfStates);
    Serial.println("Tilstand endret fremover");
  }
}

void changeStateBackward() {
  static unsigned long lastButtonPressTime2 = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastButtonPressTime2 >= 200 && state != emergencystop) {
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
