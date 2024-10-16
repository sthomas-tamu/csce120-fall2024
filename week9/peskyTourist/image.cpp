#include "image.h"

#include <iostream>

using std::endl;
using std::string;


void swap(unsigned int& a, unsigned int& b) {
    unsigned int temp = a;
    a = b;
    b = temp;
}


unsigned int getMedian(unsigned int a, unsigned int b, unsigned int c) {
    // sort local copies
    unsigned int low = a;
    unsigned int median = b;
    unsigned int high = c;
    if (low > median) {
        swap(low, median);
    }
    if (median > high) {
        swap (median, high);
    }
    if (low > median) {
        swap (low, median);
    }    

    // return middle value
    return median;
}


Pixel createMedianPixel(Pixel p1, Pixel p2, Pixel p3) {
    // TODO: return a pixel whose R/G/B values are the median of the input pixels
    Pixel result;
    result.r = getMedian(p1.r, p2.r, p3.r);
    result.g = getMedian(p1.g, p2.g, p3.g);
    result.b = getMedian(p1.b, p2.b, p3.b);
    
    return result;
}


Pixel** makeImage(unsigned int width, unsigned int height) {
    //TODO create a new 2d array of Pixels in column-major order
    Pixel** image = new Pixel*[width];
    for(unsigned int i=0; i<height; ++i) {
        image[i] = new Pixel[height];
    }
    return image;
}


// we'll assume good input
void loadImage(ifstream& ifs, Pixel**& image, unsigned int& width, unsigned int& height) {
    // get preamble data including width and height
    string type;
    ifs >> type;

    ifs >> width >> height;

    unsigned int maxColor;
    ifs >> maxColor;

    // allocate memory for the image based on width and height
    image = makeImage(width, height);

    // read in each pixel
    for (unsigned int row=0; row<height; ++row) {
        for (unsigned int col=0; col<width; ++col) {
            ifs >> image[col][row].r;
            ifs >> image[col][row].g;
            ifs >> image[col][row].b;
        }
    }
}


void outputImage(ofstream& ofs, const Pixel*const* img, unsigned int width, unsigned int height) {
    // output preamble data
    ofs << "P3" << endl; // ppm type
    ofs << width << " " << height << endl;
    ofs << 255 << endl; // max color

    // output each pixel
    for (unsigned int row=0; row<height; ++row) {
        for (unsigned int col=0; col<width; ++col) {
            ofs << img[col][row].r << " ";
            ofs << img[col][row].g << " ";
            ofs << img[col][row].b << " ";
        }
        ofs << endl;
    }
}


void deleteImage(Pixel**& image, unsigned int& width, unsigned int& height) {
    if (image != nullptr) {
        for (unsigned int col=0; col<width; ++col) {
            if (image[col] != nullptr) {
                delete[] image[col];
            }
        }
        delete[] image;
        image = nullptr;
    }
    width = 0;
    height = 0;
}

