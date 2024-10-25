#include <iostream>

using std::cout, std::endl;

void printAry(const int* _ary, unsigned int _size) {
    for(unsigned int i=0; i<_size; ++i)
        cout << _ary[i] << " ";
    cout << endl;
}

int main() {
    // & address of 
    // * value at
   
    // integers and pointers 
    int num = 20;
    int *numPtr = &num;
    int **numPtrPtr = &numPtr;
    int ***numPtrPtrPtr = &numPtrPtr;
    
    cout << "value of num:\t\t"            << num  << endl;
    cout << "address of num:\t\t" << &num << endl;
    cout << endl;

    cout << "value of numPtr:\t"   << numPtr  << endl;
    cout << "value AT numPtr:\t"   << *numPtr << endl;
    cout << "address of numPtr:\t" << &numPtr << endl;
    cout << endl;

    cout << "value of numPtrPtr:\t"   << numPtrPtr  << endl;
    cout << "value AT numPtrPtr:\t"   << *numPtrPtr << endl;
    cout << "address of numPtrPtr:\t" << &numPtrPtr << endl;
    cout << endl;

    // arrays and pointers
    int ary[5] = {1, 2, 3, 4, 5};
    int *ary2 = ary;
    
    cout << "value OF ary:\t\t" << ary << endl;
    cout << "value AT ary:\t\t";
    printAry(ary, 5);
    cout << endl;

    cout << "value OF ary2:\t\t" << ary2 << endl;
    cout << "value AT ary2:\t\t";
    printAry(ary2, 5);
    cout << endl;

    // try for 2d arrays, both contiguous and non-contiguous 

    return 0;
}
