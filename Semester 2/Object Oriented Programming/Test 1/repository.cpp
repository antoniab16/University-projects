#include <assert.h>
#include "repository.h"

Repository::Repository() : schools(DynamicVector<School>()){
}

DynamicVector<School> Repository::getAll() {
    return this->schools;
}

/// Adds the school object given as parameter to the repository
/// \param school school to be added
void Repository::addSchool(School school) {
    for(int i = 0; i< schools.get_size(); i++){
        if(schools[i].getName() == school.getName() && schools[i].getAddress() == school.getAddress())
            throw std::runtime_error("Already exists");
    }
    this->schools.add(school);
}

void Repository::getInitialSchools() {
    this->addSchool(School("Avram_Iancu", "46.77, 23.60", "15.04.2022"));
    this->addSchool(School("George_Cosbuc", "46.77, 23.58", "18.04.2022"));
    this->addSchool(School("Alexandru_Vaida", "46.77, 23.63", "23.04.2022"));
    this->addSchool(School("Romulus_Guga", "46.53, 24.57", "04.05.2022"));
    this->addSchool(School("Colegiu_Transilvania", "46.54, 24.57", "03.05.2022"));
}

void Repository::test_add() {
    Repository repo;
    repo.addSchool(School("SchoolName", "Address", "Date"));
    assert(repo.getAll().get_size() == 1);

}

/// Sorts schools from repo based on name
/// \param address address to find closest schools
/// \return schools sorted by name
DynamicVector<School> Repository::getClosSchools(string address) {
    School copy;
    DynamicVector<School> filtered_schools = schools;
    for(int i = 0; i < filtered_schools.get_size(); i++){
        for(int j = i + 1; j < filtered_schools.get_size(); j++){
            if(filtered_schools[i].getName() > filtered_schools[j].getName()){
                copy = filtered_schools[i];
                filtered_schools[i] = filtered_schools[j];
                filtered_schools[j] = copy;
            }
        }
    }
    return filtered_schools;
}



