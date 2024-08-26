#include <iostream>

using std::cout, std::endl;

int main() {
    // declare/define an array
    const unsigned int SIZE = 5;
    
    // no initialization (DON'T DO THIS, DANGEROUS!)
    int noInit[SIZE];
    
    cout << "The noInit array:" << endl;
    for (unsigned int i=0; i<SIZE; ++i) {
        cout << "noInit[" << i << "] = " << noInit[i] << endl;
    }
    cout << endl;
}
