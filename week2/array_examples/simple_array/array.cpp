#include <iostream>

using std::cout, std::endl;

int main() {
    // declare/define an array
    const unsigned int SIZE = 5; 
    /* 
        It is helpful to create a constant variable if you want to make multiple arrays 
        of all the same length. This way you only need to change the size in one place. 
        Often constants have their names in all caps, but this is not required.
    */
    int evens[SIZE]; //an array of int of size SIZE
    
    // initialize the array with iteration    
    for (unsigned int i=0; i<SIZE; ++i) {
        evens[i] = i*2;
    }

    // access a single element from the array
    cout << "The second element of the evens array is " << evens[1] << endl; //arrays are indexed starting at 0, not 1!
    
    // print the array (address)
    cout << "The evens array (memory address): " << evens << endl;

    // print values from array (includes traversal)
    cout << "The evens array elements:" << endl;
    for (unsigned int i=0; i<SIZE; ++i) {
        cout << "evens[" << i << "] = " << evens[i] << endl;
    }
    cout << endl;

    /*    

    // initialize the array with braces
    int odds[SIZE] = {1, 3, 5, 7, 9};
    cout << "The odds array:" << endl;
    for (unsigned int i=0; i<SIZE; ++i) {
        cout << "odds[" << i << "] = " << odds[i] << endl;
    }
    cout << endl;

    */
}
