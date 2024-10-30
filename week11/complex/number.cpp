#include "Complex.h"

#include <iostream>

using std::cout, std::endl;

int main() {
    Complex c1(1, 2);
    cout << "c1: " << c1 << endl;

    Complex c2(-3, -4);
    cout << "c2: " << c2 << endl;

    double d = 1.5;
    cout << "d: " << d << endl;
    cout << endl;
    
    Complex c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl << endl;

    c3 = c1 + d;
    cout << "c1 + d: " << c3 << endl << endl;

    c3 = d + c1;
    cout << "d + c1: " << c3 << endl << endl;

    return 0;
}
