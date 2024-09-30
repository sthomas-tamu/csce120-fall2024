#include <iostream>
#include <string>

using std::cout, std::endl;
using std::string;

int main() {
    string str = "Howdy!";
    cout << "My string is: " << str << endl;
    cout << "The first charater is " << str.at(0) << endl;

    string* strPtr = &str;
    cout << "My string pointer is: " << strPtr << endl;
    cout << "The string it points to is: " << *strPtr << endl;
    cout << "The first charater is " << (*strPtr).at(0) << endl;

    cout << "The first charater is " << strPtr->at(0) << endl;

    return 0;
}
