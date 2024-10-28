#include <iostream>
#include "Pixel.h"

using std::cout, std::endl, std::string;

void printPixel(string identifier, Pixel& p) {
    cout << identifier;
    cout << "\t(red): " << p.getRed();
    cout << "\t(green): " << p.getGreen();
    cout << "\t(blue): " << p.getBlue();
    cout << endl;
}

int main() {
    cout << "creating a with default constructor" << endl;
    Pixel a;
    printPixel("a", a);
    cout << endl;

    cout << "creating b with constructor passed 10, 20, 30" << endl;
    Pixel b(10, 20, 30);
    printPixel("b", b);
    cout << endl;

    cout << "creating c with copy constructor passed b" << endl;
    Pixel c = b; // equivalent to Pixel c(b);
    printPixel("c", c);
    cout << endl;

    cout << "updating a using setters with 200, 150, 100" << endl;
    a.setRed(200);
    a.setBlue(150);
    a.setGreen(100);
    printPixel("a", a);
    cout << endl;

    cout << "creating d with assignment passed a" << endl;
    Pixel d = a;
    printPixel("d", d);
    cout << endl;

    cout << "updating a to be only red and b to be only green" << endl;
    a.setRed(255);
    a.setGreen(0);
    a.setBlue(0);
    printPixel("a", a);
    b.setRed(0);
    b.setGreen(0);
    b.setBlue(255);
    printPixel("b", b);
    cout << endl;

    cout << "d = a + b;" << endl;
    d = a + b;
    printPixel("d", d);
    cout << endl;

    cout << "-d;" << endl;
    -d;
    printPixel("d", d);

    cout << endl;
    printPixel("c", c);
    cout << "c == d: " << std::boolalpha << (c==d) << endl;
    cout << endl;

    cout << "c = d;" << endl;
    c = d; // note we did not have to implement this
    printPixel("d", d);
    printPixel("c", c);
    cout << "c == d: " << std::boolalpha << (c==d) << endl;
    cout << endl;
}
