#include "Complex.h"

#include <iostream>

using std::cout, std::endl;

void print(Complex c) {
    cout << c.getReal() << " + " << c.getImaginary() << "i";
}

int main() {
    Complex c1;
    cout << "Default complex number: ";
    print(c1);
    cout << endl;

    c1.setReal(1.2);
    c1.setImaginary(3.4);
    cout << "Updated complex number: ";
    print(c1);
    cout << endl;
 

    Complex c2(-5, 1);
    cout << "Another complex number: ";
    print(c2);
    cout << endl;

 
    Complex c3(15);
    cout << "A complex number with only the real portion provided: ";
    print(c3);
    cout << endl;
 

    return 0;
}
