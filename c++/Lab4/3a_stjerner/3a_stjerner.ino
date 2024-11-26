void skrivStjerner(int antall) {
    for (int i = 0; i < antall; i++) {
        Serial.print('*');
    }
    Serial.println();  
}

void setup() {
    Serial.begin(9600); 
    while (!Serial) {
        ; 
    }
    Serial.println("Skriv et tall for å skrive ut stjerner:");
}

void loop() {
    if (Serial.available() > 0) {
        int antall = Serial.parseInt();
        skrivStjerner(antall);
    }
}
