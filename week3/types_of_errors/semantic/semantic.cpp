#include <iostream>
using std::cin, std::cout, std::endl;

// three errors

int main() {
    unsigned int age;
    cout << "Age when born: " << age << endl;

    cout << "Enter your age: ";
    cin >> age;

    if (12 < age || age < 20) {
        cout << "You are a teenager." << endl;
    }
    else if (age > 21) {
        cout << "You can vote." << endl;
    }

    return 0;
}