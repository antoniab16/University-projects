
#include "engine.h"

double Engine::getPrice()  {
    return basePrice;
}

std::string Engine::toString() {
    return "Price: " + std::to_string(basePrice);
}

ElectricEngine::ElectricEngine(double price, int autonomy) {
    this->basePrice = price;
    this->autonomy = autonomy;
}

double ElectricEngine::getPrice()  {
    return basePrice + autonomy * 0.01;
}

std::string ElectricEngine::toString() {
    return "Electric engine, Price: " + std::to_string(getPrice()) + ", Autonomy: " + std::to_string(autonomy);
}


TurboEngine::TurboEngine(double price) {
    this->basePrice = price;
}

std::string TurboEngine::toString() {
    return "Turbo engine, Price: " + std::to_string(getPrice());
}

double TurboEngine::getPrice()  {
    return basePrice + 100;
}
