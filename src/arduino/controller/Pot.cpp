#include "Pot.h"


// Costruttore
Pot::Pot(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

// Setta e restituisce il livello corrente inserito di zucchero
int Pot::getSugar() {
    int sugar = analogRead(pin);
    sugar = map(sugar, 0, 1023, 1, 4);
    return sugar;
}

