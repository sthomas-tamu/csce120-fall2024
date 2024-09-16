#include <iostream>

using std::cin, std::cout, std::endl;

void throwingFunctionA() {
    cout << "-- start of throwingFunctionA --" << endl;

    // throw an int (just for fun make it even)
    throw 4;

    cout << "-- end of throwingFunctionA --" << endl;
} 


void throwingFunctionB() {
    cout << "-- start of throwingFunctionB --" << endl;

    // throw an int (just for fun make it odd)
    throw 5;

    cout << "-- end of throwingFunctionB --" << endl;
}


int main() {
    cout << "-- start of main --" << endl;

    cout << "Select which throwing function you would like (1 or 2): ";
    int version = 0;
    cin >> version;

    if(version == 1) {
        throwingFunctionA();
    } else if (version == 2) {
        throwingFunctionB();
    } else {
        cout << "Error, invalid choice." << endl;
    }

    cout << "-- end of main --" << endl;
}
