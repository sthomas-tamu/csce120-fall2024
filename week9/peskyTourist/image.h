#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <fstream>

using std::ifstream, std::ofstream;

struct Pixel {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

Pixel createMedianPixel(Pixel p1, Pixel p2, Pixel p3);

Pixel** makeImage(unsigned int width, unsigned int height);

void loadImage(ifstream& ifs, Pixel**& image, unsigned int& width, unsigned int& height);

void outputImage(ofstream& ofs, const Pixel*const* img, unsigned int width, unsigned int height);

void deleteImage(Pixel**& image, unsigned int& width, unsigned int& height);

#endif
