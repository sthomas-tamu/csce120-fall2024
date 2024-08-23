#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;

#include "function.h"
#include <iostream>

using std::cout, std::endl;

int sumOfDigitsTwist(int number) {
    //twisted sum:
    //when reading digits, 
    //  if the digit to the left was even, add the new digit
    //  if the digit to the left was odd, add the new digit
    //  if there is no left digit, add the new digit
    //
    //  if the input number is negative, multiply the result by -1 
    //
    //code will keep track of the left digit (ld) and the right digit (rd) while reading
    //using %, it will read the digits from right to left (ones place to larger places),
    //so will multiple by -1 at the very end

    bool is_negative = number < 0; //record the sign of the input number
    if(is_negative) {
        DEBUG("number is negative");
    } else {
        DEBUG("number is positive");
    }

    int sum = 0;
    int ld = 0; //left digit
    int rd = 0; //right digit

    //extract the ones place and keep it as the right digit, 
    //will wait to adjust to sum until have seen the left digit
    rd = number % 10;
    number /= 10;
    DEBUG("extracting rd, rd is " << rd << ", number is " << number);

    while(number != 0) { //no longer checking if positive because number may be positive or negative
        //extract the left digit
        ld = number % 10;
        number /= 10;
        DEBUG("extracting ld, ld is " << ld << ", number is " << number);

        //adjust the twisted sum
        if(ld % 2 == 0) { //even
            sum += rd;
            DEBUG("ld is even, adding rd to sum, sum is " << sum);
        } else { //odd
            sum -= rd;
            DEBUG("ld is odd, substracting rd from sum, sum is " << sum);
        }

        //update the right digit to the one we just processed
        rd = ld;
        DEBUG("setting rd to ld, rd is now " << rd);
    }
    //add the final right digit
    sum += rd;
    DEBUG("adding final rd, sum is " << sum);

    //multiple by -1 if the original number was negative
    if (is_negative) {
        sum = sum * -1;
        DEBUG("number is negative, multipling sum by -1, sum is " << sum);
    }

    return sum;
}