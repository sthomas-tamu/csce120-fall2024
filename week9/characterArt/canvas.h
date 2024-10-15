#ifndef CANVAS_H
#define CANVAS_H

const unsigned int MAX_WIDTH = 80;  // standard console width
const unsigned int MAX_HEIGHT = 24; // standard console height

char** makeCanvas(unsigned int width, unsigned int height);
void releaseCanvas(char**& canvas, unsigned int& width, unsigned int& height);
void resizeCanvas(char**& canvas, unsigned int& width,  unsigned int& height, unsigned int newWidth, unsigned int newHeight);

void printCanvas(const char*const* canvas, unsigned int width, unsigned int height);

void addCharacter(char c, unsigned int row, unsigned int col, char**&, unsigned int& width, unsigned int& height);

#endif
