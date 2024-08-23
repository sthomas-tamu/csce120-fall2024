#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;

#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
    double sum = 0;
    int counter = 0;

    cout << "Enter a series of integers. Last number is -1" << endl;
    int value = 0;
    cin >> value;
    DEBUG("read in " << value);

    while (value != -1) {
        sum += value;
        counter++;
        DEBUG("sum is now " << sum << ", counter is now " << counter)

        cin >> value;
        DEBUG("read in " << value);
    }

    cout << "The average is " << sum/counter << endl;

    return 0;
}