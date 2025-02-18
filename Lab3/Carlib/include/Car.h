#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car {
    private:
        double speed;

    public:
    Car(double speed);
    void drive();
    void slow();
    void speedUp();
};

#endif