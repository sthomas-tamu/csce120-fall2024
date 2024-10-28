#include <iostream>
#include <iomanip>
#include "Date.h"

using std::cout, std::endl;

int main() {
    Date a(2023, 10, 30);
    Date b(2023, 10, 31);
    Date c(2023, 10, 30);
    cout << "a: " << a.to_string() << endl;
    cout << "b: " << b.to_string() << endl;
    cout << "c: " << c.to_string() << endl;
  
    cout << "a == b: " << std::boolalpha << (a == b) << endl;
    cout << "a == c: " << std::boolalpha << (a == c) << endl;
    cout << "a < b: " << std::boolalpha << (a < b) << endl;
    cout << "b < a: " << std::boolalpha << (b < a) << endl;
    cout << "a < c: " << std::boolalpha << (a < c) << endl;
    cout << "c < a: " << std::boolalpha << (c < a) << endl;
}
