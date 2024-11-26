void fyllArray(int arr[], int len, int potPin) {
    for (int i = 0; i < len; i++) {
        arr[i] = analogRead(potPin);
        delay(100);
    }
}

void testFyllArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        Serial.print("Verdi ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(arr[i]);
    }
}

const int len = 10;
int arr[len];
int potPin = A0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    fyllArray(arr, len, potPin);
    testFyllArray(arr, len);
    delay(1000); 
}
