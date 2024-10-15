#include "assert.h"
#include "controller.h"

Controller::Controller() : repo(Repository()){
    repo.getInitialSchools();
}

DynamicVector<School> Controller::getAll() {
    return this->repo.getAll();
}

/// Creates school object with the given parameters and adds it by using addSchool method from Repository
/// \param name name of new school
/// \param address address of new school
/// \param date date of new school
void Controller::addSchool(std::string name, std::string address, std::string date) {
    School school = School(name, address, date);
    this->repo.addSchool(school);
}

void Controller::test_add() {
    Controller controller;
    controller.addSchool("name", "address", "date");
    assert(controller.getAll().get_size() == 6);

}

/// Gets schools sorted by name closest to the address by calling the method from Repository
/// \param address address for which to find closest schools
/// \return schools  sorted by name
DynamicVector<School> Controller::getClosestSorted(string address) {
    return this->repo.getClosSchools(address);
}


