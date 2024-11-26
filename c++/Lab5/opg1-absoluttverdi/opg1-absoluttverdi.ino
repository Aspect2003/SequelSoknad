void loop(){
    int tall1 = -2;
    int tall2 = -7;

    tall1 = abs(tall1);
    abs(&tall2);
    Serial.print(tall1);
    Serial.print(tall2);
}

int abs(int tall) {
    if (tall < 0) {
        return -tall;
    }
    return tall;
}

void abs(int* tall) {
    if (*tall < 0) {
        *tall = -*tall;
    }
}

