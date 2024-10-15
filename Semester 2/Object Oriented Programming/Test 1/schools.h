#pragma once
#include <iostream>
using namespace std;

class School{
private:
    string name;
    string address;
    string date_of_visit;

public:
    School();
    School(string name_of_school, string address, string date_visit);
    string getName();
    string getAddress();
    string getDate();
};