#pragma once
#include "car.h"
#include <vector>

class Service {
private:
    std::vector<Car*> cars;
    Car* last_car_added;

public:
    Service(){}
    std::vector<Car*> getInitialCars();
    void addCar(int numberDoors, std::string engineType, int autonomy);
    std::vector<Car*> getAllCars();
    std::vector<Car*> getCarsWithMaxPrice(double maxPrice);
    void writeToFile(std::string filename, std::vector<Car*> cars);
    Car* getLastCar();
};

