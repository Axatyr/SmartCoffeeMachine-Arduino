#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Config.h"
#include "MsgService.h"

#include "Button.h"
#include "Pot.h"
#include "ServoMotor.h"
#include "Pir.h"
#include "Sonar.h"
#include "Thermometer.h"
#include "Display.h"

#include "Task.h"
#include "Timer.h"
#include "Product.h"
#include <avr/sleep.h>
#include "Arduino.h"


class TaskManager: public Task {
public:

    TaskManager();
    void init(int period);
    void tick();

private:
    // Controller
    Button* buttonUp;
    Button* buttonDown;
    Button* buttonMake;
    Pot* potSugar;
    ServoMotor* servoMotor;

    // Sensor
    Pir* pirSensor;
    Sonar* sonarSensor;
    Thermometer* temperatureSensor;
    
    // Display
    extern Display* display;

    // Assistance mode
    extern bool refill; 
    extern bool recover;
    extern int performedTest;
    
    // For sleep mode
    int afk;
    bool afkStart;
    int idleTime;

    // Product ------Da modificare il massimo------
    static const int productTypeNum = 3; //Type of product
    Product coffee = new Product("Coffee", 0, 3);
    Product tea = new Product("Tea", 0, 2);
    Product chocolate = new Product("Chocolate", 0, 2);
    Product product[productTypeNum] ={coffee, tea, chocolate};
    int currProductIndex; 
    int prodFinished; //Used to check status product
    int sugar;
    
    // Period check
    unsigned long currCheckTime;
    unsigned long timeCheck = 180000;

    // Temperature 
    int tempMin = 17;
    int tempMax = 24;

    // Sonar relevation
    int distTrigger = 40;
    int timeoutTime = 5000; 
    int currTimeWaiting;

    // Making product
    int makingTime = 10000;
    int makingProductTime;

    // State of machine
    enum { BOOT, READY, SELECTION, EXECUTION, WAITING_CUSTOMER, STANDBY, ASSISTANCE, SELF_TEST} state;
};

#endif