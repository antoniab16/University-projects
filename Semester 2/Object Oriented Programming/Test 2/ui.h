#pragma once
#include "service.h"

class UI {
private:
    Service service;
public:
    UI();
    void run();
    void printCars();
};
