#include "Pir.h"


// Costruttore
Pir::Pir(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);
}

// Rileva la presenza, HIGH = true, LOW = false
bool Pir::isDetected(){
  return digitalRead(pin) == HIGH;
}
