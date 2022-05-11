#ifndef SONAR_H
#define SONAR_H

class Sonar {

  private:
    const float vs = 331.5 + 0.6*20;
    int echoPin, trigPin;

  public:
    Sonar(int echoPin, int trigPin);
    float getDistance();

};

#endif
