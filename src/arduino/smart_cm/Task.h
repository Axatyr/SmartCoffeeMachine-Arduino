#ifndef TASK_H
#define TASK_H

class Task {
  protected:
    int myPeriod;
    int timeElapsed;

  public:
    virtual void init(int period){
      myPeriod = period;
      timeElapsed = 0;
    }

    virtual void tick() = 0;

    bool updateAndCheckTime(int basePeriod){
      timeElapsed += basePeriod;
      if (timeElapsed >= myPeriod){
        timeElapsed = 0;
        return true;
      } else {
        return false;
      }
    }

};

#endif
