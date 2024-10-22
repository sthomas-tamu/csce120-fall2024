#include <iostream>
#include <stdexcept>
#include <sstream>
#include "canvas.h"

using std::cout, std::endl;

char** makeCanvas(unsigned int width, unsigned int height) {
    // allocate on heap and initialize with ' ' spaces
    // use row major order

    cout << "DEBUG: makeCanvas" << endl;

    char** canvas = new char*[height];
    for (unsigned int row=0; row<height; ++row) {
        canvas[row] = new char[width];
        for (unsigned int col=0; col<width; ++col) {
            canvas[row][col] = ' ';
        }
    }

    return canvas;
}


void releaseCanvas(char**& canvas, unsigned int& width, unsigned int& height) { 
    // release memory on the heap
    // because row major order, delete each row, then delete the canvas
    // reset width and height to 0

    cout << "DEBUG: releaseCanvas" << endl;

    for (unsigned int row=0; row<height; ++row) {
        delete[] canvas[row];
    }
    delete[] canvas;
  
    canvas = nullptr;
    width = 0;
    height = 0;
}


void resizeCanvas(char**& canvas, unsigned int& width,  unsigned int& height, unsigned int newWidth, unsigned int newHeight) {
    // resize canvas to new height and width using existing functions to help

    cout << "DEBUG: resizeCanvas" << endl;

    // check if need to resize
    if ((newWidth == width) && (newHeight == height)) {
        cout << "DEBUG: requesting identical canvas in both dimensions, resize not needed" << endl;
        return;
    }

    //TODO
    // make new canvas
    char** newCanvas = makeCanvas(newWidth, newHeight);
  
    // copy over data
    for(unsigned int row=0; row<width; ++row)
        for(unsigned int col=0; col<height; ++col)
            newCanvas[row][col] = canvas[row][col];
  
    // delete old memory
    releaseCanvas(canvas, width, height);
  
    // update canvas reference variables
    canvas = newCanvas;
    width = newWidth;
    height = newHeight;
}


void printCanvas(const char*const* canvas, unsigned int width, unsigned int height) {
    cout << "DEBUG: printCanvas" << endl;

    for (unsigned int col=0; col<width+2; ++col) {
        cout << "-";
    }
    cout << endl;

    for (unsigned int row=0; row<height; ++row) {
        cout << "|";
        for (unsigned int col=0; col<width; ++col) {
            cout << canvas[row][col];
        }
        cout << "|" << endl;
    }

    for (unsigned int col=0; col<width+2; ++col) {
        cout << "-";
    }
    cout << endl;
}


void addCharacter(char c, unsigned int row, unsigned int col, char**& canvas, unsigned int& width, unsigned int& height) {
    // only add printable characters to the canvas
    // check if character location will fit on canvas, otherwise resize
  
    cout << "DEBUG: addCharacter" << endl;
 
    // check if character is printable 
    if (!isprint(c)) {
        throw std::invalid_argument("Character must be printable");
    }

    // check if location fits the console limits
    if (row >= MAX_HEIGHT) {
        std::ostringstream errorMessage;
        errorMessage << "row must be less than " << MAX_HEIGHT << ", you entered " << row;
        throw std::invalid_argument(errorMessage.str());
    }
    if (col >= MAX_WIDTH) {
        std::ostringstream errorMessage;
        errorMessage << "col must be less than " << MAX_WIDTH <<", you entered " << col;
        throw std::invalid_argument(errorMessage.str());
    }

    // check if location is available in current size
    unsigned int newHeight = std::max(height, row + 1);
    unsigned int newWidth = std::max(width, col + 1);
    if ((height != newHeight) || (width != newWidth)) {
        resizeCanvas(canvas, width, height, newWidth, newHeight);
    }

    // update the character
    canvas[row][col] = c;
}

