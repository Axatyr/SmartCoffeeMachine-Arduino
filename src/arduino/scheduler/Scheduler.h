#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "../utils/Timer.h"
#include "../task/Task.h"
#define MAX_TASKS 10

class Scheduler {

 int basePeriod;
 int nTasks;
 Task* taskList[MAX_TASKS];
 Timer timer;
public:

 void init(int basePeriod);
 virtual bool addTask(Task* task);
 virtual void schedule();

};

#endif