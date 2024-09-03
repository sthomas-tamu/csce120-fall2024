#include <iostream>
using std::cin, std::cout, std::endl;

// one error

int main() {
    unsigned int age = 0;
    cout << "Enter your age: ";
    cin >> age;
    
    if (12 < age && age < 20) {
        cout << "You are a teenager." << endl;
    }
    else if (age = 21) {
        cout << "You can vote." << endl;
    }
    cout << "Your age times " << (100 / age)
         << " is a century." << endl;

    return 0;
}
