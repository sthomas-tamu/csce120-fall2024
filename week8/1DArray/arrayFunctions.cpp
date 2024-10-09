#include <iostream>
#include "arrayFunctions.h"
#include <algorithm>

using std::cin, std::cout, std::endl;

// print including empty
void print(const int ary[], unsigned int size) {
  /*
  cout << "DEBUG: print: ary = " << ary << endl;
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << " ";
  }
  cout << endl;
  */

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

// UPDATED!
void loadRandom(unsigned int newSize, int*& ary, unsigned int& size) {
  /* //no longer needed
  if(newSize > CAPACITY) {
    throw std::out_of_range("size cannot be greater than " + std::to_string(CAPACITY));
  }
  */

  size = newSize;

  // release the memory for the existing array
  if(ary != nullptr) {
    delete[] ary;
  }

  // create a new array
  ary = new int[size];

  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand() % 100;
  }

  /*
  cout << "DEBUG: load: ary = " << ary << endl;
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << " ";
  }
  cout << endl;
  */
}

//UPDATED!
void insert(int val, unsigned int index, int*& ary, unsigned int& size) {
  /*
  // check if array already full (at CAPACITY)  
  // if so, throw an exception
  if (size == CAPACITY) {
    throw std::invalid_argument("array already at capacity, can only hold " + std::to_string(CAPACITY) + " elements");
  }
  */

  // check if requesting to insert past the current size
  // if so, throw an exception
  if (index > size) { 
    throw std::out_of_range("index must be between 0 and " + std::to_string(size));
  }

  // make room to insert the new element
  // update newAry instead
  int* newAry = new int[size+1];
  for (unsigned int i = size; i > index; --i) {
    //ary[i] = ary[i-1];
    newAry[i] = ary[i-1];
  }

  // insert the new element
  //ary[index] = val;
  newAry[index] = val;

  // copy over remaining elements into newAry
  for (unsigned int i=index; i>0; --i) {
    newAry[i-1] = ary[i];
  }

  // increment size
  size++;

  // release the memory for the old ary and point it to newAry
  delete[] ary;
  ary = newAry;

  newAry = nullptr; // good habit but not needed since function is ending
}

//UPDATE not needed, can just use less of the memory already allocated
void removeAtIndex(unsigned int index, int ary[], unsigned int& size) {
  // check if requesting to remove past the size and do nothing
  if (index >= size) { // note index can't be negative so don't need to check
    throw std::out_of_range("index must be between 0 and " + std::to_string(size-1));
  }
  
  // move each element after index back one
  for (unsigned int i = index; i < size; i++) {
    ary[i] = ary[i+1];
  }
  size--;
}

//UPDATE not needed, can just use less of the memory already allocated
void removeFirstOf(int val, int ary[], unsigned int& size) {
  for (unsigned int i=0; i<size; ++i) {
    if (ary[i] == val) {
      removeAtIndex(i, ary, size); // removeAtIndex automatically updates size
      return;
    }
  }
  cout << "Warning, item not found, nothing removed from array" << endl;
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

