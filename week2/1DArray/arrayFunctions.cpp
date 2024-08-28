#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;


// print including empty
void print(const int ary[], unsigned int size) {
  if (size == 0) {
    cout << "Empty Array" << endl;

  } else {
    for (unsigned int i=0; i<size; ++i) {
      cout << ary[i] << " ";
    }
    cout << endl;
  }
}


void loadRandom(int ary[], unsigned int size) {
  size = std::min(size, CAPACITY); // making sure size is not ever larger than CAPACITY

  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand() % 100;
  }
}


void insert(int val, unsigned int index, int ary[], unsigned int size) {
  cout << "Not implemented yet." << endl;
}


void removeAtIndex(unsigned int index, int ary[], unsigned int size) {
  cout << "Not implemented yet." << endl;
}

void removeFirstOf(int val, int ary[], unsigned int size) {
  cout << "Not implemented yet." << endl;
}


int getMax(const int ary[], unsigned int size) {
  cout << "Not implemented yet." << endl;
  return 0;
}


int getMin(const int ary[], unsigned int size) {
  cout << "Not implemented yet." << endl;
  return 0;
}


unsigned int countVal(int val, const int ary[], unsigned int size) {
  cout << "Not implemented yet." << endl;
  return 0;
}

