#include <iostream>
using std::cout, std::endl;

// 4 errors

int main() {
    unsignd int age = 0;
    cout << "Enter your age: ";
    cin >> age;

    if (12 < age < 20) {
        cout >> "You are a teenager." >> endl;
    }

    return 0;
}