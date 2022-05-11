#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal.h>
#include "Config.h"
#include <Arduino.h>

class Display {

    private:
        int rs; // Selezione registro
        int e; // Abilitazione operazioni lettura/scrittura
        int d4; // Bus dati per scambio info
        int d5; // Bus dati per scambio info
        int d6; // Bus dati per scambio info
        int d7; // Bus dati per scambio info

        LiquidCrystal lcd;

    public:
        Display(int rs, int e, int d4, int d5, int d6, int d7);
        void init();
        void printNewMessage(String text);
};

#endif 