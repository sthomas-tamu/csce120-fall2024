#include <iostream>

using std::cout, std::endl;

const unsigned int SIZE = 5; 
/* 
    It is helpful to create a constant variable if you want to make multiple arrays 
    of all the same length. This way you only need to change the size in one place. 
    Often constants have their names in all caps, but this is not required.
*/


void PrintArray(std::string label, int ary[SIZE]) {
   cout << "The " << label << " array elements:" << endl;
   for (unsigned int i=0; i<SIZE; ++i) {
        cout << label << "[" << i << "] = " << ary[i] << endl;
    }
    cout << endl;
}

int main() {
    // declare/define an array
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
    PrintArray("evens", evens);

    // initialize the array with braces
    int odds[SIZE] = {1, 3, 5, 7, 9};
    PrintArray("odds", odds);

    //initialize the array to default
    int defaultArray[SIZE] = {};
    PrintArray("defaultInit", defaultArray);
}
