#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;

#include <iostream>
#include "function.h"

using std::cout, std::cin, std::endl;

int main() {
    cout << "Enter an integer" << endl;
    int x = 0;
    cin >> x;
    DEBUG("read in " << x);

    cout << "the sum of digits is " << sumOfDigitsTwist(x) << endl;

    return 0;
}