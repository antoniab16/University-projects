#pragma once
#include "engine.h"
class Car {
private:
    int numberOfDoors;
    Engine* engine;
public:
    Car(){}
    Car(int numberDoors, Engine* engine);
    double computePrice();
    int getNumberDoors();
    Engine* getEngine();
};
