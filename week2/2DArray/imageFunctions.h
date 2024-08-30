#ifndef IMAGE_FUNCTIONS_H
#define IMAGE_FUNCTIONS_H

#include <string>

const unsigned int MAX_WIDTH = 1920;  // max width of image
const unsigned int MAX_HEIGHT = 1080; // max height of image

// a Pixel struct representing a single red, green, blue pixel value for an image
struct Pixel {
  unsigned int r = 0; // red
  unsigned int g = 0; // green
  unsigned int b = 0; // blue
};

void printMenu();

void processImage(char choice, Pixel image[MAX_WIDTH][MAX_HEIGHT]);

void loadImage(const std::string filename, Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height);

void outputImage(const std::string filename, const Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height);

void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height, bool quiet = false);

void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height);

void invertImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height, bool quiet = false);


void invertGrayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height);

#endif
