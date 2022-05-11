#include "TaskManager.h"
#include <LiquidCrystal.h>

// Display
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

TaskManager::TaskManager() {
    buttonUp = new Button(BTN_UP_PIN);
    buttonDown = new Button(BTN_DW_PIN);
    buttonMake = new Button(BTN_MAKE_PIN);
    potSugar = new Pot(POT_PIN); 
    servoMotor = new ServoMotor(SERVO_PIN);
    pirSensor = new Pir(PIR_PIN);
    sonarSensor = new Sonar(SONAR_ECHO, SONAR_TRIG);
    temperatureSensor = new Thermometer(TEMP_PIN);
}

void TaskManager::init(int period) { 
    Task::init(period);
    lcd.begin(16, 2);
    state = BOOT;
}

void TaskManager::tick() {
    switch(state) {
       
        case STANDBY: {
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            sleep_enable();
            sleep_mode();
            sleep_disable();

            if(pirSensor->isDetected()) {
                afk = 0;
                state = READY;
            }
            break;
        }
        case BOOT: {
            // Welcome message
            lcd.print("Boot SmartCoffee");
            delay(5000); 

            // Initialize product
            sugar = 2;
            for(int i=0; i < productTypeNum; i++){
                product[i]->setCurrQuantity(product[i]->getQuantityMax());
            }
            refill = false;

            //Ready
            currCheckTime = millis();
            afkStart = false;
            MsgService.sendMsg("Working");
            state = READY;
            break;
        }
        case READY: {
            
            // Check if pir detect and start countdown for sleep mode
            if(millis() - afk < idleTime){
                afkStart = false;
                MsgService.sendMsg("Idle");
                state = STANDBY;
            }
            if(!pirSensor->isDetected() && afkStart == false) {
                afk = millis();
                afkStart = true;
            } else if(pirSensor->isDetected()){
                afk = 0;
                afkStart = false;
            }

            // Check self-test
            if(millis() - currCheckTime > timeCheck){
                state = SELF_TEST;
            }
            
            // Check status product
            prodFinished = 0;
            for(int i=0; i < productTypeNum; i++){
                if(product[i]->getCurrQuantity() == 0){
                    prodFinished++;
                }
                MsgService.sendMsg(product[i]->getName() + product[i]->getCurrQuantity());
            }

            if(prodFinished == productTypeNum){
                refill = true;
                MsgService.sendMsg("Assistance");
                state = ASSISTANCE;
            }

            if(state == READY){
                lcd.print("Ready");

                // Select sugar
                if(sugar != potSugar->getSugar()){
                    sugar = potSugar->getSugar();
                    lcd.print("Sugar level: " + String(sugar));
                    delay(5000);
                    lcd.print("Ready");
                }
                
                // Waiting selection product
                if(buttonUp->isPressed() || buttonDown->isPressed()){
                    state = SELECTION;
                }
            }
            break;
        }
        case SELECTION: {
            currProductIndex = 0; // First product selected
            unsigned long startCount = millis(); // Save time selection
            // Loop for select product
            while(millis() - startCount < 5000 ){
                lcd.print(product[currProductIndex]->getName());
                // Go back
                if(buttonDown->isPressed()){
                    startCount = millis();
                    if(currProductIndex > 0){
                    currProductIndex--;
                    } else {
                        currProductIndex = 2;
                    }
                }  // Go foreward
                else if(buttonUp->isPressed()){
                    startCount = millis();
                    if(currProductIndex < 2){
                    currProductIndex++;
                    } else {
                        currProductIndex = 0;
                    }
                }  // Make order
                else if(buttonMake->isPressed()){
                    // Check if product is avaible, otherwise return error
                    if(product[currProductIndex]->getCurrQuantity() >0){
                        product[currProductIndex]->decrease();
                        state = EXECUTION; 
                    } else {
                        lcd.print("Product finished");
                    }
                }
            }
            state = READY;
            break;
        }
        case EXECUTION: {
            lcd.print("Making " + product[currProductIndex]->getName());

            makingProductTime = millis();
            servoMotor->makingOrder();

            if(millis() - makingProductTime < makingTime) {
                lcd.print("The " + product[currProductIndex]->getName() + "is ready");
                currTimeWaiting = millis();
                state = WAITING_CUSTOMER;
            }
            break;
        }
        case WAITING_CUSTOMER: {
            // gestore sensore 
            if(sonarSensor->getDistance() >= distTrigger || millis()- currTimeWaiting < timeoutTime) {
                servoMotor->reset();
                state = READY;
            }

            break;
        }
        case ASSISTANCE: {
            lcd.print("Assistance Required");

            // Refill error
            if(refill == false){
                // Refill products
                for(int i = 0; i < productTypeNum; i++){
                    product[i]->setCurrQuantity(product[i]->getQuantityMax());
                }
            }

            // Self-Test error
            if(refill == false && recover == false){
                state = READY;
            }
            break;
        }
        case SELF_TEST: {
            //movimento servo andata ritorno
            servoMotor->makingOrder();
            servoMotor->reset();

            // Check Temperature
            int currTemp = temperatureSensor->getTemperature();
            if(currTemp >= tempMin && currTemp <= tempMax){
                performedTest++; // Increase test passed successfuly
                currCheckTime = millis(); // Restore time for next self-test
                MsgService.sendMsg("SelfTestPassed");
                state = READY; 
            } else {
                recover = true;
                MsgService.sendMsg("Assistance");
                state = ASSISTANCE;
            }
            break;
        }
    }
}
