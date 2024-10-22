#include "Pixel.h"
#include <iostream>

using std::cout, std::endl;

int main() {
    try {
        Pixel p1;
        cout << "Pixel p1: ";
        p1.print(cout);
        cout << endl;
  
        Pixel p2 = Pixel(10, 20, 30);
        cout << "Pixel p2: ";
        p2.print(cout);
        cout << endl;

        Pixel p3 = Pixel(100, 200, 300);
        cout << "Pixel p3: ";
        p3.print(cout);
        cout << endl;
    }
    catch (std::exception& e) {
        cout << "Error, exception encountered: " << e.what() << endl;
    }
  
    return 0;
};

