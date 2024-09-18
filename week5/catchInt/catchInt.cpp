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


void errorMessage(int errorCode) {
    cout << "-- start of errorMessage --" << endl;

    if(errorCode % 2 == 0) {
        cout << "caught even error" << endl;
    } else {
        cout << "caught odd error" << endl;
    }

    cout << "-- end of errorMessage --" << endl;
}


int main() {
    cout << "-- start of main --" << endl;

    cout << "Select which throwing function you would like (1, 2, or 3): ";
    int version = 0;
    cin >> version;

    if(version == 1) {
        try {
            throwingFunctionA();
        } catch (int e) {
            errorMessage(e);
        }
    } else if (version == 2) {
        try {
            throwingFunctionB();
        } catch (int e) {
            errorMessage(e);
        }
    } else if (version == 3) {
        try {
            throwingFunctionA();
            throwingFunctionB();
        } catch (int e) {
            errorMessage(e);
        }
    } else {
        cout << "Error, invalid choice." << endl;
    }

    cout << "-- end of main --" << endl;
}
