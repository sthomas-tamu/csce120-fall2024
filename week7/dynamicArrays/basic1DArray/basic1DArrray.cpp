#include <iostream>
#include <stdexcept>

using std::cout, std::cin, std::endl;

void printAry(const double nums[], unsigned int size);

double max(const double nums[], unsigned int size);

int main() {
    // input the number of values/size of the array
    cout << "How many values will you enter? ";
    unsigned int size = 0;
    cin >> size;
    if (cin.fail() || size == 0) {
        cout << "You must enter a valid size greater than zero." << endl;
        return -1; // empty array so nothing to read into
    }

    // TODO: update ary to be dynamic, then don't need these next two lines!
    cout << "I can only to 10 values! I need to be updated. Please enter 10 values anyway. " << endl;
    size = 10;
   
    // TODO: update the ary declaration to instead be a double* and use new to create it on the heap
    double ary[10];
  
    // initialize
    for (unsigned int i=0; i<size; ++i) {
        ary[i] = 0;
    }
  
    // set values of items in the array, works the same way as with fixed-size arrays  
    for (unsigned int i=0; i<size; ++i) {
        cin >> ary[i]; // do this
        if (cin.fail()) {
            cout << "not a valid number for index " << i << endl;
            return -1;
        }
    }
  
    cout << "You entered: " << endl;
    printAry(ary, size);
    cout << endl;
  
    cout << "The max value is: " << max(ary, size) << endl;

    // TODO: release the ary memory you created on the heap

    return 0;
}


void printAry(const double nums[], unsigned int size) {
    if (size == 0) {
        cout << endl;
        return;
    }

    for (unsigned int i=0; i<size; ++i) {
        cout << nums[i] << " ";
        if ((i+1) % 5 == 0) {
            cout << endl;
        }
    }  
}


double max(const double nums[], unsigned int size) {
    if (size == 0) {
        throw std::invalid_argument("Cannot find max for an empty array");
    }

    double max = nums[0];
    for (unsigned int i=1; i<size; ++i) { // start at 1 since index 0 already addressed
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

