#include "Thermometer.h"
#include <Arduino.h>

Thermometer::Thermometer(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

uint8_t Thermometer::getTemperature() {
    int current_temp = analogRead(this->pin);
    float voltage = current_temp * AREF_VOLTAGE;
    voltage /= 1024.0;
    int temperature = (voltage - 0.5) * 100;
    return temperature;
}

String Thermometer::toString() {
    return getTemperature() + " °C";
}