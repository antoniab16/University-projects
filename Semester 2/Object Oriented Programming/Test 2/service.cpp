#include <fstream>
#include "service.h"

std::vector<Car *> Service::getInitialCars() {
    Engine* e1 = new ElectricEngine(3000, 500);
    Engine* e2 = new TurboEngine(3000);
    Engine* e3 = new ElectricEngine(3000, 835);
    Car* c1 = new Car(2, e1);
    Car* c2 = new Car(2, e2);
    Car* c3 = new Car(4, e3);
    cars.push_back(c1);
    cars.push_back(c2);
    cars.push_back(c3);
    return cars;
}

std::vector<Car *> Service::getAllCars() {
    return cars;
}

void Service::addCar(int numberDoors, std::string engineType, int autonomy) {
    Engine* e;
    if(engineType == "Electric")
        e = new ElectricEngine(3000, autonomy);
    else if(engineType == "Turbo")
        e = new TurboEngine(3000);
    else
        return;
    Car* car = new Car(numberDoors, e);
    cars.push_back(car);
    last_car_added = car;
}

Car *Service::getLastCar() {
    return last_car_added;
}

void Service::writeToFile(std::string filename, std::vector<Car*> cars) {
    std::ofstream file("../" + filename);
    for(auto* car:cars) {
        file << "Number of doors: " << car->getNumberDoors() << ", Price:" << car->computePrice() << " ,"
             << car->getEngine()->toString() << "\n";
    }
    file.close();
}

std::vector<Car *> Service::getCarsWithMaxPrice(double maxPrice) {
    std::vector<Car*> cars_with_less_price;
    for(auto* car:cars){
        if(car->computePrice() < maxPrice)
            cars_with_less_price.push_back(car);
    }
    return cars_with_less_price;
}
