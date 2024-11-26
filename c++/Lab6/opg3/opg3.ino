#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
const int knapp1 = 2;
const int knapp2 = 3;

DHT dht(DHTPIN, DHTTYPE);

// Definer debounce tid
const int debounce_time = 200;
unsigned long last_interrupt1 = 0;
unsigned long last_interrupt2 = 0;

// Struct for temperatur og luftfuktighet
struct TempHum {
  float temperatur;
  float luftfuktighet;
};

// Array for å lagre TempHum-data
TempHum tempHumArray[100];
volatile int index = 0;

volatile bool knapp1Trykket = false;
volatile bool knapp2Trykket = false;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(knapp1, INPUT);  // Bruk intern pull-up
  pinMode(knapp2, INPUT);  // Bruk intern pull-up

  attachInterrupt(digitalPinToInterrupt(knapp1), knapp1Handler, RISING);
  attachInterrupt(digitalPinToInterrupt(knapp2), knapp2Handler, RISING);
}

void loop() {
  if (knapp1Trykket) {
    knapp1Trykket = false;  // Tilbakestill flagget
    if (index < 100) {
      float temperatur = dht.readTemperature();
      float luftfuktighet = dht.readHumidity();

      if (isnan(temperatur) || isnan(luftfuktighet)) {
        Serial.println("Feil ved lesing av data fra DHT11!");
      } else {
        tempHumArray[index].temperatur = temperatur;
        tempHumArray[index].luftfuktighet = luftfuktighet;
        index++;
        Serial.print("Data lagret: Temp = ");
        Serial.print(temperatur);
        Serial.print(" C, Luftfuktighet = ");
        Serial.println(luftfuktighet);
      }
    }
  }

  if (knapp2Trykket) {
    knapp2Trykket = false;  // Tilbakestill flagget
    if (index > 0) {
      float totalTemperatur = 0;
      float totalLuftfuktighet = 0;

      for (int i = 0; i < index; i++) {
        totalTemperatur += tempHumArray[i].temperatur;
        totalLuftfuktighet += tempHumArray[i].luftfuktighet;
      }

      float gjennomsnittTemp = totalTemperatur / index;
      float gjennomsnittFukt = totalLuftfuktighet / index;

      Serial.print("Gjennomsnittstemperatur: ");
      Serial.print(gjennomsnittTemp);
      Serial.print(" C, Gjennomsnittsluftfuktighet: ");
      Serial.println(gjennomsnittFukt);
    }
  }
}

void knapp1Handler() {
  // Sjekk debounce for knapp 1
  if (millis() - last_interrupt1 > debounce_time) {
    knapp1Trykket = true;
    last_interrupt1 = millis();
  }
}

void knapp2Handler() {
  // Sjekk debounce for knapp 2
  if (millis() - last_interrupt2 > debounce_time) {
    knapp2Trykket = true;
    last_interrupt2 = millis();
  }
}
