#ifndef POT_H
#define POT_H

#include "Arduino.h"

class Pot {
    
    private:
        int pin;

    public:
        Pot(int pin);
        int getSugar();            
};

#endif
