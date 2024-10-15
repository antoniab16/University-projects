#pragma once
#include "dynamic_vector.h"

class Repository{
private:
    DynamicVector<School> schools;

public:
    Repository();
    DynamicVector<School> getAll();
    void addSchool(School school);
    void getInitialSchools();
    void test_add();
    DynamicVector<School> getClosSchools(string address);
};
