#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include "ServoTimer2.h"
#include "Arduino.h"

class ServoMotor {

    private:
        int pin;
        ServoTimer2 motor;

    public:
        ServoMotor(int pin);

        virtual void on();
        virtual void setPosition(int angle);
        virtual void off();

        virtual void makingOrder(); // Rotate from 0 to 180
        virtual void reset(); // Rotate form 180 to 0, 

    
};

#endif
