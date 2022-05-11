#ifndef COMM_TASK_H
#define COMM_TASK_H

#include "Task.h"
#include "Config.h"
#include "MsgService.h"

class CommTask: public Task {
    private:
      extern bool refill; 
      extern bool recover;
      extern int performedTest;

    public:

      CommTask();
      void init(int period);
      void tick();

};

#endif