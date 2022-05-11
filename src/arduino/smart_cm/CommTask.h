#ifndef COMM_TASK_H
#define COMM_TASK_H

#include "Task.h"
#include "Config.h"
#include "MsgService.h"

extern bool refill; 
extern bool recover;
extern int performedTest;

class CommTask: public Task {

    public:

      CommTask();
      void init(int period);
      void tick();

};

#endif