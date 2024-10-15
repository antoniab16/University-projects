#include "ui.h"
#include "tests.h"

int main(){
    Test test;
    test.testAll();
    cout<<"Tests passed"<<endl;
    UI ui = UI();
    ui.run();
}