#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <iostream>

using namespace std;

int main() {

	testAll();
	cout << "Short tests over" << endl;
    test_extra_operation();
    cout << "Extra operation test over" << endl;
	testAllExtended();
	cout << "All test over" << endl;
}