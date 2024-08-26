#include <iostream>

using std::cout, std::endl;

const unsigned int SIZE = 10; //size of arrays


void PrintArray(std::string label, int ary[SIZE]) {
    cout << "The " << label << " array elements:" << endl;
    for (unsigned int i=0; i<SIZE; ++i) {
        cout << label << "[" << i << "] = " << ary[i] << endl;
    }
    cout << endl;
}


int main() {
    // declare/define an array
    int evens[SIZE];
    for (unsigned int i=0; i<SIZE; ++i) {
        evens[i] = i*2;
    }
    PrintArray("evens", evens);

    //copy the array
}
