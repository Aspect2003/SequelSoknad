#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temperaturer[10]; 
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  lesTemperaturer();
  float gjennomsnitt = beregnGjennomsnitt();
  Serial.print("Gjennomsnittstemperatur: ");
  Serial.println(gjennomsnitt);
  while (1); 
}

void lesTemperaturer() {
  for (int i = 0; i < 10; i++) {
    temperaturer[i] = dht.readTemperature();
    Serial.print("Temperatur ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(temperaturer[i]);
    delay(10000); 
  }
}

float beregnGjennomsnitt() {
  float sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += temperaturer[i];
  }
  return sum / 10;
}
