#pragma once
#include "controller.h"

class UI{
private:
    Controller controller;
public:
    UI();
    void print_schools(DynamicVector<School> schools);
    void run();

};