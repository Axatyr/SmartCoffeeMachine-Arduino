#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

class Button {
  
  private:
    int pin;
  
  public:
    Button(int pin);
    bool isPressed();
 
};

#endif
