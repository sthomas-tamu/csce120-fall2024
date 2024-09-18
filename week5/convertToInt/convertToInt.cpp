#include <iostream>
#include <string>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string term; // constructor initialzies to empty string

    do {
        cout << "Enter string to convert to an integer or '.' to exit: ";
        cin >> term;
  
        if(term != ".") {
            size_t size = 0;
            // the following code may throw an exception, add try/catch around it
            int value = std::stoi(term, &size); 
            cout << term << " times 2 is " << (value * 2) << endl;
        }
    } while (term != ".");

    return 0;
}
