#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
#include <string>

#include "imageFunctions.h"

using std::cin, std::cout, std::endl;
using std::numeric_limits, std::streamsize;
using std::ofstream, std::ifstream;
using std::string;


/*  Function printMenu
 *  Return value: none
 */
// You should not modify this function unless you add another processing option. //
void printMenu()
{
  cout << "----------------------------------" << endl;
  cout << " 'G': Make grayscale image" << endl;
  cout << " 'S': Make sepia image" << endl;
  cout << " 'I': Make invert grayscale image" << endl;
  cout << " 'N': Make invert image" << endl;
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
 *
 *  Note the function prototype is not included in the header file since this is an internal function
 *  for the processImage function and should not be exposed to outside use.
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
    case 'I':
      invertGrayscaleImage(image, width, height);
      outputImageFilename = "invert_grey." + originalImageFilename;
      break;
    case 'N':
      invertImage(image, width, height);
      outputImageFilename = "invert." + originalImageFilename;
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
// You should not modify this function. //
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

  // read in maximum color value, for us it must be 255
  unsigned int maxColor = 0;
  ifs >> maxColor;

  // read the color values into the 2D array in Column Major Order
  for (unsigned int row=0; row < height; ++row) {
    for (unsigned int col=0; col < width; ++col) {
      ifs >> image[col][row].r;
      ifs >> image[col][row].g;
      ifs >> image[col][row].b;
    }
  }
}


/*  Function outputImage
 *  filename: c-string which is the ppm file to write
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but ppm file should be created
 */
// You should not modify this function. //
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
  for (unsigned int row=0; row < height; ++row) {
    for (unsigned int col=0; col < width; ++col) {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
}


/*  Function grayscale
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be grayscale colors
 * 
 *  Note: computing grayscale as the average of the R,G,B chanels for each pixel
 */
void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height, bool quiet)
{
  if(!quiet) {
    cout << "Making grayscale image... " << endl;
  }
  // iterate through 2d image of Pixels and convert them to grayscale
  // use opposite outer loop than load and output just to be different
  for (unsigned int col=0; col < width ; ++col) {
    for (unsigned int row=0; row < height; ++row) {
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
 *
 *  Note: compute sepia as follows for each pixel:
 *        new red =   0.393 * red + 0.768 * green + 0.189 * blue
 *        new green = 0.349 * red + 0.686 * green + 0.168 * blue
 *        new blue =  0.272 * red + 0.534 * green + 0.131 * blue
 *        remember that the max color we allow is 255
 */
// You should write this function. //
void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  cout << "Making sepia image... " << endl;
  for (unsigned int col=0; col < width ; ++col) {
    for (unsigned int row=0; row < height; ++row) {
      unsigned int newRed = 0.393 * image[col][row].r + 0.768 * image[col][row].g + 0.189 * image[col][row].b;
      unsigned int newGreen = 0.349 * image[col][row].r + 0.686 * image[col][row].g + 0.168 * image[col][row].b;
      unsigned int newBlue = 0.272 * image[col][row].r + 0.534 * image[col][row].g + 0.131 * image[col][row].b;

      unsigned int maxColor = 255;
      newRed = std::min(newRed, maxColor);
      newGreen = std::min(maxColor, newGreen);
      newBlue = std::min(maxColor, newBlue);

      image[col][row] = {newRed, newGreen, newBlue};
    }
  }
}


/*  Function invertGrayscaleImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be invert grayscale
 */
// You should write this function. //
void invertGrayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height)
{
  cout << "Making invert grayscale image... " << endl;

  grayscaleImage(image, width, height, true);
  invertImage(image, width, height, true);  
}

/*  Function invertGrayscaleImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be invert grayscale
 */
// You should write this function. //
void invertImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], unsigned int width, unsigned int height, bool quiet)
{
  if(!quiet) {
    cout << "Making invert grayscale image... " << endl;
  }
  for (unsigned int col=0; col < width ; ++col) {
    for (unsigned int row=0; row < height; ++row) {
      unsigned int newRed = 255 - image[col][row].r;
      unsigned int newGreen = 255 - image[col][row].g;
      unsigned int newBlue = 255 - image[col][row].b;

      image[col][row] = {newRed, newGreen, newBlue};
    }
 }  

}
