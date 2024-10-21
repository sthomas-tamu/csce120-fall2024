#include <iostream>
#include "canvas.h"

using std::cin, std::cout, std::endl;

int main() {
    // creates a canvas where you can place characters at locations
    // will dynamically resize canvas as needed, up to the maximum console size
  
    // canvas variables
    char** art = nullptr;
    unsigned int width = 0;
    unsigned int height = 0;
  
    bool quit = false;
    while(!quit) {
        // read in a character and location
        char c = ' ';
        unsigned int row = 0;
        unsigned int col = 0;
        try {
            cout << "Enter character to add: ";
            cin >> c;
            if (cin.fail()) {
                // reset cin and throw an exception
		        cin.clear(); 
		        cin.ignore();
                throw std::invalid_argument("Character read failed");
            }
        
            cout << "Enter where to add (row and col): ";
            cin >> row;
            if (cin.fail()) {
                // reset cin and throw an exception
		        cin.clear();
		        cin.ignore();
                throw std::invalid_argument("Invalid input for row");
            }
            cin >> col;
            if (cin.fail()) {
                // reset cin and throw an exception
		        cin.clear();
		        cin.ignore();
                throw std::invalid_argument("Invalid input for col");
            }
    
            // add the character to the canvas and print
            addCharacter(c, row, col, art, width, height);
            printCanvas(art, width, height);
        }
        catch (std::exception& e) {
            cout << e.what() << endl;
        }
        
        // ask if we need to add another character
        cout << "Add another character? (y/n) ";
        char quitChar = ' ';
        cin >> quitChar;
        quit = (tolower(quitChar) != 'y');
    }

    // release canvas memory
    releaseCanvas(art, width, height);
}
