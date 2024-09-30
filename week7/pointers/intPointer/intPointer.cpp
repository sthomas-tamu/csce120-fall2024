#include <iostream>

using std::cout, std::endl;

int main() {
    // declare two integers and initialize them
    cout << "declaring some integers:" << endl;
    int i = 4;
    cout << "i:";
    cout << "\taddress = " << &i;
    cout << "\tvalue = " << i;
    cout << endl;

    int j = 5;
    cout << "j:";
    cout << "\taddress = " << &j;
    cout << "\tvalue = " << j;
    cout << endl;

    // declare an integer pointer and initialize to point to integer i
    cout << endl << "declaring a pointer that points to i:" << endl;
    int* k = &i;
    cout << "k:";
    cout << "\taddress = " << &k;
    cout << "\tvalue = " << k;
    cout << "\tpoints to = " << *k;
    cout << endl;

    // update the integer pointer to point to integer j
    cout << endl << "updating the pointer to point to j:" << endl;
    k = &j;
    cout << "k:";
    cout << "\taddress = " << &k;
    cout << "\tvalue = " << k;
    cout << "\tpoints to = " << *k;
    cout << endl;

    // update j directly
    cout << endl << "updating j directly:" << endl;
    j = 10;
    cout << "j:";
    cout << "\taddress = " << &j;
    cout << "\tvalue = " << j;
    cout << endl;
    cout << "k:";
    cout << "\taddress = " << &k;
    cout << "\tvalue = " << k;
    cout << "\tpoints to = " << *k;
    cout << endl;

    // update the data that k points to
    cout << endl << "updating the integer's value that k points to through k:" << endl;
    *k = 15;
    cout << "j:";
    cout << "\taddress = " << &j;
    cout << "\tvalue = " << j;
    cout << endl;
    cout << "k:";
    cout << "\taddress = " << &k;
    cout << "\tvalue = " << k;
    cout << "\tpoints to = " << *k;
    cout << endl;

    return 0;
}
