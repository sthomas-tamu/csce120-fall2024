#include <iostream>
#include "functions.h"

using namespace std;

int main() {
  // declare/define image 2d array of Pixels
  // would be too big for the stack, so 'static' puts it somewhere else but scope is still in main
  static Pixel image[MAX_WIDTH][MAX_HEIGHT];
  
  char menuChoice = ' '; // selected menu option
  do {
    printMenu();
    cin >> menuChoice;
    switch (toupper(menuChoice)) { // use toupper so user can input upper or lower case choices
      case 'G':
      case 'S':
      case 'R':
        processImage(menuChoice, image);
        break;
      case 'Q': // does nothing but needed or default will execute
        break;
      default:
        cout << endl << "'" << menuChoice << "' is not a valid option'" << endl << endl;
    }
  } while (toupper(menuChoice) != 'Q'); // use toupper so user can input upper or lower case choices
}