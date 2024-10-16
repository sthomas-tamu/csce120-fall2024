#include <iostream>
#include "arrayFunctions.h" // don't include the cpp file! 

using std::cin, std::cout, std::endl;

void printMenu(); // function implementation will be given later in the file


int main() {
  // seed the random number generator with the current time to get different numbers every time
  // when debugging, can be helpful to comment this out so you have the same numbers every time
  srand(time(NULL));
  
  // UPDATED
  // initialize the ary to all 0's and set size to 0
  //int ary[CAPACITY] = {0};
  int* ary = nullptr;
  unsigned int size = 0;
  unsigned int capacity = 0;
 
  char menuChoice = ' ';

  // print the choices until the user wants to quit
  while ('Q' != toupper(menuChoice)) { // clean up input data by convering character to upper case 
  
    printMenu();
    
    cout << endl << "What would you like to do? ";
    cin >> menuChoice;
    cout << endl;

    // declaring variables that will be used inside the switch statement
    // c++ does not allow declaring them inside the switch because case statements are only labels
    int num = 0;
    unsigned int index = 0;
    unsigned int newSize = 0;

    try {
      
      switch (toupper(menuChoice)) { // clean up input data by converting character to upper case
        case 'L':
          cout << "Input number of random values to load: ";
          cin >> newSize;
  
          loadRandom(newSize, ary, size, capacity);
          break;
  
        case 'I':
          cout << "Input value to insert: ";
          cin >> num;
          
          cout << "Input index to insert: ";
          cin >> index;
  
          insert(num, index, ary, size, capacity); 
          break;
  
        case 'R':
          cout << "Input index to delete: ";
          cin >> index;
  
          removeAtIndex(index, ary, size);
          break;
  
        case 'F':
          cout << "Input value to delete: ";
          cin >> num;
  
          removeFirstOf(num, ary, size);
          break;
  
        case 'X':
          cout << "Max: " << getMax(ary, size) << endl;
          break;
  
        case 'N':
          cout << "Min: " << getMin(ary, size) << endl;
          break;
  
        case 'C':
          cout << "Input value to count: ";
          cin >> num;
  
          cout << num << " appears " << countVal(num, ary, size) << " times" << endl;
          break;
  
        case 'P':
          print(ary, size);
          break;
  
        case 'S':
          cout << "Size: " << size << endl;
          break;
  
        case 'Q':
          cout << "Goodbye!" << endl;
          break;
  
        default:
          throw std::invalid_argument("Invalid input, try again.");        
          break;
      }
    }
    catch (std::exception& e) {
      cout << "Error: " << e.what() << endl;
    }
  }

  // UPDATED
  // delete any allocated memory for ary
  if(ary != nullptr) {
    delete[] ary;
  }

}

void printMenu() {
  cout << endl;
  cout << "'L' - Load random values" << endl;
  cout << "'I' - Insert number at index" << endl;
  cout << "'R' - Remove number at index" << endl;
  cout << "'F' - Remove first instance of value" << endl;
  cout << "'X' - Get maximum value" << endl;
  cout << "'N' - Get miniumum value" << endl;
  cout << "'C' - Count instances of number" << endl;
  cout << "'P' - Print values" << endl;
  cout << "'S' - Size" << endl;
  cout << "'Q' - Quit" << endl;
}
