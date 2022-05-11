#include "Scheduler.h"
#include "CommTask.h"
#include "TaskManager.h"
#include "Display.h"
#include "MsgService.h"

Scheduler* sched = new Scheduler();
Display* display = new Display(); // Messa fuori per poter accedere tramite extern

bool refill = true;
bool recover = false;
int performedTest = 0;

void setup() {

    Serial.begin(9600);

    // Inizializzazione display
    diplay->init();

    // Scheduler initialization
    sched->init(50);

    // Launch message service
    MsgService.init();

    // Add task for communicate with app
    CommTask* commTask = new CommTask();
    commTask->init(50);
    sched->addTask(commTask);

    // Add main task
    TaskManager* coffeeManager = new TaskManager();
    coffeeManager->init(50);
    sched->addTask(coffeeManager);
}

void loop() {
    sched->schedule();
}
