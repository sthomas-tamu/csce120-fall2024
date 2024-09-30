#include <iostream>

using std::cout, std::endl, std::flush;

int main() {
    // declare an interger pointer but don't initialize
    int* k; 
    cout << "k:\t";
    cout << "address = " << &k << "\t" << flush;
    cout << "value = " << k << "\t" << flush;
    cout << "points to = " << *k << flush;
    cout << endl;

    // set it to the nullptr
    k = nullptr;
    cout << "k:\t";
    cout << "address = " << &k << "\t" << flush;
    cout << "value = " << k << "\t" << flush;
    cout << "points to = " << *k << flush;
    cout << endl;

    return 0;
}
