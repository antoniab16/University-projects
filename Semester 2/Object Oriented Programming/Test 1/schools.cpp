
#include "schools.h"

School::School() {
}

School::School(string name_of_school, string address, string date_visit) {
    this->name = name_of_school;
    this->address = address;
    this->date_of_visit = date_visit;
}

string School::getName() {
    return this->name;
}

string School::getAddress() {
    return this->address;
}

string School::getDate() {
    return this->date_of_visit;
}
