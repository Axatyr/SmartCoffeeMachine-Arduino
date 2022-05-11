#ifndef TIMER_H
#define TIMER_H

class Timer {

    public:
    Timer();
    void setupFreq(int freq);
    /* period in ms */
    void setupPeriod(int period);
    void waitForNextTick();

};


#endif