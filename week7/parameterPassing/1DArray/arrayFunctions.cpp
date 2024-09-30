#include <iostream>
#include "arrayFunctions.h"
#include <algorithm>

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
  if(size > CAPACITY) {
    throw std::out_of_range("size cannot be greater than " + std::to_string(CAPACITY));
  }

  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand() % 100;
  }
}


void insert(int val, unsigned int index, int ary[], unsigned int size) {
  // check if array already full (at CAPACITY)  
  // if so, throw an exception
  if (size == CAPACITY) {
    throw std::invalid_argument("array already at capacity, can only hold " + std::to_string(CAPACITY) + " elements");
  }

  // check if requesting to insert past the current size
  // if so, throw an exception
  if (index > size) { 
    throw std::out_of_range("index must be between 0 and " + std::to_string(size));
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
    throw std::out_of_range("index must be between 0 and " + std::to_string(size-1));
  }
  
  // move each element after index back one
  for (unsigned int i = index; i < size; i++) {
    ary[i] = ary[i+1];
  }
}


bool removeFirstOf(int val, int ary[], unsigned int size) {
  for (unsigned int i=0; i<size; ++i) {
    if (ary[i] == val) {
      removeAtIndex(i, ary, size);
      return true;
    }
  }
  cout << "Warning, item not found, nothing removed from array" << endl;
  return false;
}


int getMax(const int ary[], unsigned int size) {
  if(size == 0) {
    throw std::invalid_argument("cannot find maximum of empty array");
  }

  // will look for the max using the champion approach (keep the current winner)
  int maxVal = ary[0];

  for (unsigned int i=1; i<size; ++i) {
    maxVal = std::max(maxVal, ary[i]);
  }

  return maxVal;
}


int getMin(const int ary[], unsigned int size) {
  if(size == 0) {
    throw std::invalid_argument("cannot find minimum of empty array");
  }

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

