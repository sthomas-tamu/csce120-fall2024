#include<iostream>

using std::cout, std::cin, std::endl;

// short range is -32768 to 32767

int main() {
    short a=0, b=0;
    do {
        cout << "Enter two numbers to add: ";
        cin >> a >> b;
        short answer = a + b;
        cout << a << " + " << b << " is " << answer << endl;
    } while (a >=0 || b >=0);
}