#include <iostream>
#include "multiplyFunctions.h"

using std::cin, std::cout, std::endl;

int main() {
  unsigned int rows = 0, cols = 0;

  cout << "How many row and columns for multiplication table? (Max 9 for either) ";  
  cin >> rows >> cols;

  if (cin.fail()) {
    cout << "Number of rows or columns is not a valid integer." << endl;
    return -1;
  }

  if (rows == 0 || cols == 0) {
    cout << "You must have at least one row and one column." << endl;
    return -1;
  }
  if (rows > 9 || cols > 9) {
    cout << "You can't have a row or column over 9." << endl;
    return -1;
  }
  
  int** mults = nullptr;
  makeTable(mults, rows, cols);
  
  for (unsigned int row=0; row<rows; ++row) {
    for (unsigned int col=0; col<cols; ++col) {
      mults[row][col] = (row+1)*(col+1);
    }
  }
  
  printTable(mults, rows, cols);
  
  releaseTable(mults, rows, cols);

  return 0;
}

