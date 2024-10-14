#include <iostream>

using std::cin, std::cout, std::endl;

// using column major ordering

void loadary(char* ary, unsigned int rows, unsigned int cols);
void printary(const char* ary, unsigned int rows, unsigned int cols);

int main() {
  srand(time(NULL));

  unsigned int rows = 0;
  cout << "Enter the number of rows: ";
  cin >> rows;
  if(cin.fail() or rows == 0) {
    cout << "ERROR, invalid input for number of rows, must be an integer >= 1\n";
    return -1;
  }

  unsigned int cols = 0;
  cout << "\nEnter the number of columns: ";
  cin >> cols;
  if(cin.fail() or cols == 0) {
    cout << "ERROR, invalid input for number of columns, must be an integer >= 1\n";
    return -1;
  }

  char* ary = nullptr;

  // allocate memory
  ary = new char[cols * rows];
  
  // initialize
  loadary(ary, rows, cols);

  // use
  printary(ary, rows, cols);

  // release memory
  delete [] ary;
  ary = nullptr;
  rows = 0;
  cols = 0;
}

void loadary(char* ary, unsigned int rows, unsigned int cols) {
  // can have col or row be the outer loop, it doesn't matter
  for (unsigned int col=0; col<cols; col++) {
    for (unsigned int row=0; row<rows; row++) {
      char val;
      if (rand()%2) { // uppercase
        val = rand()%26 + 'A';
      }
      else { // lowercase
        val = rand()%26 + 'a';
      }
      ary[row * cols + col] = val;
      // alternatively *(ary + row * cols + col) = val;
    }
  }
}

void printary(const char* ary, unsigned int rows, unsigned int cols) {
  // must print with row in outer loop to match our mental model
  for (unsigned int row=0; row<rows; row++) {
    for (unsigned int col=0; col<cols; col++) {
      cout << ary[row * cols + col] << " ";
      // alternatively cout << *(ary +row * cols + col) << " ";
    }
    cout << endl;
  }
}
