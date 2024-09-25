#include <iostream>
#include <sstream>

using std::cin, std::cout, std::endl, std::string, std::getline, std::istringstream, std::boolalpha;

int main() {
    // read in a line of input, place in a istringstream
    cout << "Enter something, followed by the return key. The code will attempt to extract an integer from it." << endl;
    string line;
    getline(cin, line);
    istringstream iss(line);

    int z = -99;
    iss >> z;
    cout << "z: " << z << endl;

    cout << "iss.eof(): " << boolalpha << iss.eof() << endl;
    cout << "iss.fail(): " << boolalpha << iss.fail() << endl;
    cout << "iss.bad(): " << boolalpha << iss.bad() << endl;
    cout << "iss.good(): " << boolalpha << iss.good() << endl;
    cout << endl; 

    return 0; 
}
