#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "Arduino.h"

#define AREF_VOLTAGE 3.3

class Thermometer {

    private:
        int pin;

    public:
        Thermometer(int pin);
        int getTemperature();
        String toString();
};

#endif