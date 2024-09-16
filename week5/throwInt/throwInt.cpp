#include <iostream>

using std::cin, std::cout, std::endl;

void throwingFunction1() {
    cout << "-- start of throwingFunction1 --" << endl;

    // throw an int (just for fun make it even)
    throw 4;

    cout << "-- end of throwingFunction1 --" << endl;
} 


void throwingFunction2() {
    cout << "-- start of throwingFunction2 --" << endl;

    // throw an int (just for fun make it odd)
    throw 5;

    cout << "-- end of throwingFunction2 --" << endl;
}


int main() {
    cout << "-- start of main --" << endl;

    cout << "Select which throwing function you would like (1 or 2): ";
    int version = 0;
    cin >> version;

    if(version == 1) {
        throwingFunction1();
    } else if (version == 2) {
        throwingFunction2();
    } else {
        cout << "Error, invalid choice." << endl;
    }

    cout << "-- end of main --" << endl;
}
