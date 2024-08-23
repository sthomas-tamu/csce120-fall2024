#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;

#include "function.h"
#include <iostream>

using std::cout, std::endl;

int sumOfDigits(int number) {
    int sum = 0;

    while(number > 0) {
        sum += number % 10;
        DEBUG("sum is " << sum);
        number /= 10;
        DEBUG("x is " << number);
    }

    return sum;
}