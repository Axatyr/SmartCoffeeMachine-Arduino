#include "Display.h"

// Costruttore
Display::Display() {
    this->rs = RS;
    this->e = E;
    this->d4 = D4;
    this->d5 = D5;
    this->d6 = D6;
    this->d7 = D7;

    lcd(rs, e, d4, d5, d6, d7);
}

void init() {
    lcd.begin(16, 2);
}

void printNewMessage(String text) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(text);
}