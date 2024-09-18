#include <iostream>

using std::cin, std::cout, std::endl, std::string;

void A(bool cause_exception, string padding); // passing along padding string so easier to see nested function calls
void B(bool cause_exception, string padding); // passing along padding string so easier to see nested function calls
void C(bool cause_exception, string padding); // passing along padding string so easier to see nested function calls
void D(bool cause_exception, string padding); // passing along padding string so easier to see nested function calls


int main() {
    cout << "-- start of main --" << endl;

    cout << "Would you like to throw an exception? y or n" << endl;
    char input;
    cin >> input;

    if(std::toupper(input) == 'Y') {
        A(true, "  ");
    } else if(std::toupper(input) == 'N') {
        A(false, "  ");
    } else {
        cout << "invalid option, exiting." << endl;
    }

    cout << "-- end of main --" << endl;
    return 0;
}


void A(bool cause_exception, string padding) {
    cout << padding << "-- start of A --" << endl;

    B(cause_exception, padding + "  ");

    cout << padding << "-- end of A --" << endl;
}


void B(bool cause_exception, string padding) {
    cout << padding << "-- start of B --" << endl;

    try {
        C(cause_exception, padding + "  ");
    } catch (...) {
        cout << padding << "B: caught an exception from C" << endl;
    }

    cout << padding << "-- end of B --" << endl;
}


void C(bool cause_exception, string padding) {
    cout << padding << "-- start of C --" << endl;

    D(cause_exception, padding + "  ");

    cout << padding << "-- end of C --" << endl;
}


void D(bool cause_exception, string padding) {
    cout << padding << "-- start of D --" << endl;

    if (cause_exception) {
        cout << padding << "D is calling a function that throws an exception" << endl;
        string s = "hi";
        s.at(3);
    } else {
        cout << padding << "D is doing nothing" << endl;
    }

    cout << padding << "-- end of D --" << endl;
}
