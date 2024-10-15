
#include "car.h"

Car::Car(int numberDoors, Engine* engine) {
    this->numberOfDoors = numberDoors;
    this->engine = engine;
}

double Car::computePrice() {
    double basePrice = 0;
    if(numberOfDoors == 2)
        basePrice = 7000;
    else if(numberOfDoors == 4)
        basePrice = 8500;
    return basePrice + engine->getPrice();
}

int Car::getNumberDoors() {
    return this->numberOfDoors;
}

Engine *Car::getEngine() {
    return this->engine;
}


