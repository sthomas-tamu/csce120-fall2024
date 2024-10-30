#include <iostream>
#include "Pixel.h"

using std::cout, std::endl, std::string;

int main() {
    cout << "creating a with default constructor" << endl;
    Pixel a;
    cout << "a: " << a << endl;
    cout << endl;

    cout << "creating b with constructor passed 10, 20, 30" << endl;
    Pixel b(10, 20, 30);
    cout << "b: " << b << endl;
    cout << endl;

    cout << "creating c with copy constructor passed b" << endl;
    Pixel c = b; // equivalent to Pixel c(b);
    cout << "c: " << c << endl;
    cout << endl;

    cout << "updating a using setters with 200, 150, 100" << endl;
    a.setRed(200);
    a.setBlue(150);
    a.setGreen(100);
    cout << "a: " << a << endl;
    cout << endl;

    cout << "creating d with assignment passed a" << endl;
    Pixel d = a;
    cout << "d: " << d << endl;
    cout << endl;

    cout << "updating a to be only red and b to be only green" << endl;
    a.setRed(255);
    a.setGreen(0);
    a.setBlue(0);
    cout << "a: " << a << endl;
    b.setRed(0);
    b.setGreen(0);
    b.setBlue(255);
    cout << "b: " << b << endl;
    cout << endl;

    cout << "d = a + b;" << endl;
    d = a + b;
    cout << "d: " << d << endl;
    cout << endl;

    cout << "-d;" << endl;
    -d;
    cout << "d: " << d << endl;

    cout << endl;
    cout << "c: " << c << endl;
    cout << "c == d: " << std::boolalpha << (c==d) << endl;
    cout << endl;

    cout << "c = d;" << endl;
    c = d; // note we did not have to implement this
    cout << "d: " << d << endl;
    cout << "c: " << c << endl;
    cout << "c == d: " << std::boolalpha << (c==d) << endl;
    cout << endl;
}
