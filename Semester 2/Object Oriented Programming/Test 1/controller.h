#pragma once
#include "repository.h"

class Controller{
private:
    Repository repo;
public:
    Controller();
    DynamicVector<School> getAll();
    void addSchool(string name, string address, string date);
    void test_add();
    DynamicVector<School> getClosestSorted(string address);
};