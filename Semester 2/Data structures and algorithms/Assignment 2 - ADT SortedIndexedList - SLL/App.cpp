#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    testAll();
    testAllExtended();
    test_removeBetween();
    std::cout<<"Test remove between"<<std::endl;
    std::cout<<"Finished IL Tests!"<<std::endl;
}