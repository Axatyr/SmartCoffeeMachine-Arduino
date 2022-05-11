#include "ServoMotor.h"

#define START_PROCESS 0
#define END_PROCESS 180

ServoMotor::ServoMotor(int pin) {
  this->pin = pin;  
} 

void ServoMotor::on() {
    motor.attach(pin);    
}

void ServoMotor::setPosition(int angle) {
    motor.write(angle);              
}

void ServoMotor::off() {
    motor.detach();    
}

void ServoMotor::makingOrder() {
    //ruota fino a 180
    motor.write(END_PROCESS);
}

void ServoMotor::reset() {
    motor.write(START_PROCESS);
}
