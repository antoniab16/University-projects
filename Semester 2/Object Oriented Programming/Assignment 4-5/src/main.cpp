#include <iostream>
#include "ui.h"
#include "tests.h"

using namespace std;

int main(){
    UI ui = UI();
    Tests test;
    test.testAll();
    ui.run();
    return 0;
}