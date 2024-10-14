#include <iostream>
#include <iomanip>
#include "multiplyFunctions.h"

using std::cin, std::cout, std::endl;
using std::setw; // used to adjust printing spacing

// TODO
void makeTable(int**& table, unsigned int rows, unsigned int cols) {
  // (avoid a memory leak, release any data table is already pointing to)
  // -- hint, use releaseTable so you don't have to duplicate code
  // -- this is easier if you do this part after you implement everything else
  
  // create 2d array on the heap

  // initialize elements in the 2d array
}


//TODO
void releaseTable(int**& table, unsigned int& rows, unsigned int& cols) {
  // release memory from the heap and set variables to values consistent with an empty array
  // -- no memory leaks!
}



void printTable(const int*const* table, unsigned int rows, unsigned int cols) {
  if (rows == 0 || cols == 0) {
    throw std::invalid_argument("Must have at least one row and one column");
  }

  // print header
  cout << setw(3) << "|";
  for (unsigned int col=0; col<cols; ++col) {
    cout << setw(3) << (col+1);
  }
  cout << endl;
  for (unsigned int col=0; col<=cols; ++col) {
    cout << "---";
  }
  cout << endl;

  // print table values
  for (unsigned int row=0; row<rows; ++row) {
    cout << (row+1) << " |";
    for (unsigned int col=0; col<cols; ++col) {
      cout << setw(3) << table[row][col];
    }
    cout << endl;
  }
}

