#ifndef PIR_H
#define PIR_H

#include "Arduino.h"

class Pir {

  private:
    int pin;

  public: 
    Pir(int pin);
    bool isDetected();

};

#endif
