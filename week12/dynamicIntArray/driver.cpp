#include <iostream>
#include "DynamicIntArray.h"

using std::cout, std::endl;

void printArray(std::string label, const DynamicIntArray& ary);

int main() {
  // declare and print some arrays, exercises constructors
  cout << "Constructing some dynamic int arrays:" << endl;
  DynamicIntArray a;
  printArray("with default constructor: a", a);

  /*
  DynamicIntArray b(3, 4);
  printArray("with constructor for 3 elements equal to 4: b", b);

  DynamicIntArray c(5);
  printArray("with constructor for 5 elements but no value specified: c", c);

  // exercise array indexing
  cout << endl << "Updating c by indexing:" << endl;
  c.at(2) = 9;
  c[0] = 1;
  printArray("changed at index 0 and 2: c", c);

  // exercise push_back
  cout << endl << "Using push_back on b:" << endl;
  b.push_back(8);
  printArray("b", b);

  // exercise copy constructor
  cout << endl << "Creating d with copy constructor from b:" << endl;
  DynamicIntArray d = b;
  printArray("d", d);

  // make sure was a deep copy
  d.push_back(-1);
  cout << "pushing back -1 on d, making sure was a deep copy of b:" << endl;
  printArray("b", b);
  printArray("d", d);

  // exercise assignment
  cout << endl << "Assigning a to c:" << endl;
  a = c;
  printArray("a", a);

  // make sure was a deep copy
  cout << endl << "Changing last element of a, making sure was a deep copy of c:" << endl;
  a.at(a.size()-1) = 11;
  printArray("a", a);
  printArray("c", c);
  */
}

void printArray(std::string label, const DynamicIntArray& ary) {
  cout << label << ": ";
  if (ary.empty()) {
    cout << "Empty!" << endl;
  } else {
    for (size_t i=0; i<ary.getSize(); ++i) {
      cout << ary.at(i) << " ";
    }
    cout << endl;
  }
}
