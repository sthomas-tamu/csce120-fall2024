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

      // start a new line every 10 elements
      if ((i+1) % 10 == 0) {
        cout << endl;
      }
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
  // check if requesting to insert past the maximum capacity and do nothing
  if (index >= CAPACITY) { // note index can't be negative so don't need to check
    // would be nice to warn the user of the bad input if it happens
    return;
  }
  
  // check if requesting to insert past the current size
  // if so, move index to be the next available entry
  if (index > size) { 
    index = size;
  }

  // make room to insert the new element
  for (unsigned int i = size; i > index; --i) {
    ary[i] = ary[i-1];
  }

  // insert the new element
  ary[index] = val;
}


void removeAtIndex(unsigned int index, int ary[], unsigned int size) {
  // check if requesting to remove past the size and do nothing
  if (index >= size) { // note index can't be negative so don't need to check
    // would be nice to warn the user of the bad input if it happens
    return;
  }
  
  // move each element after index back one
  for (unsigned int i = index; i < size; i++) {
    ary[i] = ary[i+1];
  }
}


void removeFirstOf(int val, int ary[], unsigned int size) {
  for (unsigned int i=0; i<size; ++i) {
    if (ary[i] == val) {
      removeAtIndex(i, ary, size);
      return;
    }
  }
}


int getMax(const int ary[], unsigned int size) {
  // assuming array has at least 1 element, could be nice and warn the user of the bad input...

  // will look for the max using the champion approach (keep the current winner)
  int maxVal = ary[0];

  for (unsigned int i=1; i<size; ++i) {
    maxVal = std::max(maxVal, ary[i]);
  }

  return maxVal;
}


int getMin(const int ary[], unsigned int size) {
  // assuming array has at least 1 element, could be nice and warn the user of the bad input...

  // will look for the min using the champion approach (keep the current winner)
  int minVal = ary[0];

  for (unsigned int i=1; i<size; ++i) {
    minVal = std::min(minVal, ary[i]);
  }

  return minVal;
}


unsigned int countVal(int val, const int ary[], unsigned int size) {

  unsigned int count = 0;

  for (unsigned int i=0; i<size; ++i) {
    if (ary[i] == val) {
      count++;
    }
  }

  return count;
}

