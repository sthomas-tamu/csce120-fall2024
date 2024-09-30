#include <iostream>

using std::cout, std::endl;

void printAry(int ary[], size_t size) {
    ary[0] = -1; //causes a side effect!
  
    cout << "printAry:";
    for (size_t i=0; i<size; ++i) {
      cout << " " << ary[i];
    }
    cout << endl;
}

int main() {
    int ary[] = {5, 7, 9};
    size_t size = 3;

    // print the array
    cout << "ary:";
    cout << "\taddress = " << ary;
    cout << "\telements =";
    for(size_t i=0; i<size; i++) {
        cout << " " << ary[i];
    }
    cout << endl;

    // use pointer arithmetic to print elements of the array
    cout << endl;
    cout << "ary:";
    cout << "\taddress = " << ary;
    cout << "\telements =";
    for(size_t i=0; i<size; i++) {
        cout << " " << *(ary + i);
    }
    cout << endl;

    cout << endl;
    printAry(ary, size);
    cout << "ary:";
    cout << "\taddress = " << ary;
    cout << "\telements =";
    for(size_t i=0; i<size; i++) {
        cout << " " << ary[i];
    }
    cout << endl;
 
    return 0;
}
