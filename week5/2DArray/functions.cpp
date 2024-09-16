#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
#include <string>
#include "functions.h"

using std::cin, std::cout, std::endl;
using std::numeric_limits, std::streamsize;
using std::ofstream, std::ifstream;
using std::string;

/*  Function processImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-array of Pixels (structs)
 *  Return value: none
 */
// You should not modify this function unless you add another processing option. //
void processImage(char choice, Pixel image[MAX_WIDTH][MAX_HEIGHT])
{
  string originalImageFilename;
  unsigned int width = 0, height = 0;

  // get filename, width and height from user
  cout << "Image filename: ";
  cin >> originalImageFilename;
  width = getInteger("width", 1, MAX_WIDTH);    // ensure user does not input value greater than the MAX_WIDTH for our array
  height = getInteger("height", 1, MAX_HEIGHT); // ensure user does not input value greater than the MAX_HEIGHT for our array

  try
  {
    // load image
    loadImage(originalImageFilename, image, width, height);

    string outputImageFilename;

    // modify image
    switch (toupper(choice))
    {
    case 'G':
      grayscaleImage(image, width, height);
      outputImageFilename = "grey." + originalImageFilename;
      break;
    case 'S':
      sepiaImage(image, width, height);
      outputImageFilename = "sepia." + originalImageFilename;
      break;
    case 'R':
      reverseGrayscaleImage(image, width, height);
      outputImageFilename = "reverse_grey." + originalImageFilename;
      break;
    }

    // output image
    outputImage(outputImageFilename, image, width, height);
  }
  catch (std::exception &e)
  {
    cout << e.what() << endl;
  }
}

/*  Function loadImage
 *  filename: string which is the ppm file to read
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  return: nothing, but image array should be loaded with values from file
 */
// You should complete this function. //
void loadImage(const string filename, Pixel image[MAX_WIDTH][MAX_HEIGHT], 
               unsigned int width, unsigned int height)
{
  cout << "Loading image..." << endl;
  ifstream ifs(filename); // input file stream opened with filename 

  // check if it's open
  if (!ifs.is_open()) {
    throw std::invalid_argument("Unable to open file: " + filename);
  }

  // we were able to open the file

  // read in Image type, for us it must be P3
  string type;
  ifs >> type;

  // read in width and height
  unsigned int fileWidth = 0, fileHeight = 0;
  ifs >> fileWidth >> fileHeight;
  if (fileWidth != width || fileHeight != height) {
    throw std::invalid_argument("Input width and/or height does not match file");   
  }
  if (width > MAX_WIDTH) {
    throw std::out_of_range(width + " cannot be greater than" + MAX_WIDTH);
  }
  if (height > MAX_HEIGHT) {
    throw std::out_of_range(height + " cannot be greater than" + MAX_HEIGHT);
  }


  // read in maximum color value, for us it must be 255
  unsigned int maxColor = 0;
  ifs >> maxColor;

  // read the color values into the 2D array in Column Major Order
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      ifs >> image[col][row].r;
      ifs >> image[col][row].g;
      ifs >> image[col][row].b;
    }

  }

}

/*  Function grayscale
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be grayscale colors
 */
void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  cout << "Making grayscale image... " << endl;
  // iterate through 2d image of Pixels and convert them to grayscale
  // use opposite outer loop than load and output just to be different
    for (unsigned int col=0; col<width; ++col) {
    for (unsigned int row=0; row<height; ++row) {
      unsigned int newColor = (image[col][row].r + image[col][row].g + image[col][row].b)/3;
      image[col][row] = {newColor, newColor, newColor};
    }
  }

 }

/*  Function sepiaImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be sepia colors
 */
// You should write this function. //
void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  cout << "Making sepia image... " << endl;
  // iterate through 2d image of Pixels and convert them to sepia
}

/*  Function reverseGrayscaleImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be reverse grayscale
 */
// You should write this function. //
void reverseGrayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  cout << "Making reverse grayscale image... " << endl;
  // iterate through 2d image of Pixels and convert them to reverse grayscale
}

/*  Function outputImage
 *  filename: c-string which is the ppm file to write
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but ppm file should be created
 */
void outputImage(const string filename, const Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  cout << "Outputting image..." << endl;

  // open output file
  ofstream ofs(filename);

  if (!ofs.is_open()) {
    throw std::invalid_argument("Unable to create output file: " + filename);
  }

  // output image type, P3 for us
  ofs << "P3" << endl;

  // output width and height, don't forget to separate by a space
  ofs << width << " " << height << endl;

  // output max color value, for us 255
  ofs << 255 << endl;

  // output from column major order array into row major PPM file
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
}

/*  Function printMenu
 *  Return value: none
 */
// You should not modify this function. //
void printMenu()
{
  cout << "----------------------------------" << endl;
  cout << " 'G': Make grayscale image" << endl;
  cout << " 'S': Make sepia image" << endl;
  cout << " 'R': Make reverse grayscale image" << endl;
  cout << " 'Q': Quit" << endl;
  cout << "----------------------------------" << endl;
  cout << endl
       << "Please enter your choice: ";
}

/*  Function getInteger
 *  label: label for outputing what the user is inputting, it should work when used as "Please enter <label>"
 *  min: int value indicating the smallest value the user should provide
 *  max: int value indicating the largest value the user should provide
 *  Return value: int value within the range min <= value <= max
 */
// You should not modify this function. //
unsigned int getInteger(const string label, unsigned int min, unsigned int max)
{
  // get value from user repeatedly until input matches requirements
  unsigned int num = 0;
  do
  {
    cin.clear();                                         // reset stream states
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

    cout << "Please enter " << label << " (" << min << " - " << max << "): ";
    cin >> num;
  } while (!cin.good() || num < min || num > max); // while input does not match requirements
  return num;
}