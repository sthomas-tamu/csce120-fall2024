#include "image.h"

#include <iostream>

using std::cout, std::endl;
using std::string;


int main() {
    // hard coding filenames, but could read these in from user
    string filename1 = "first.ppm";
    string filename2 = "second.ppm";
    string filename3 = "third.ppm";
    string filenameOut = "result.ppm";

    try {
        ifstream file1(filename1);
        ifstream file2(filename2);
        ifstream file3(filename3);
        ofstream outFile(filenameOut);

        if (!file1.is_open() || !file2.is_open() || !file3.is_open() || !outFile.is_open()) {
            cout << "ERROR, unable to open all files" << endl;
            return -1;
        }

        Pixel** img1 = nullptr;
        Pixel** img2 = nullptr;
        Pixel** img3 = nullptr;
        Pixel** result = nullptr;

        unsigned int width = 0;
        unsigned int height = 0;

        // Load & create 2D arrays

        loadImage(file1, img1, width, height);

        unsigned int loadWidth = 0; // set to parameters of first image and ensure other images match
        unsigned int loadHeight = 0;
        
        loadImage(file2, img2, loadWidth, loadHeight);
        if (width != loadWidth || height != loadHeight) {
            throw std::invalid_argument(filename1 + " height and width do not match " + filename2);  
        }

        loadImage(file3, img3, loadWidth, loadHeight);
        if (width != loadWidth || height != loadHeight) {
            throw std::invalid_argument(filename3 + " height and width do not match " + filename2);  
        }

        // Make result image
        result = makeImage(width, height);

        // Process out that pesky tourist
        // TODO: set every Pixel of the result image to be the median r/g/b value from the input images
        for(unsigned int col = 0; col<width; col++) {
            for(unsigned int row = 0; row<height; row++) {
                result[col][row] = createMedianPixel(img1[col][row], img2[col][row], img3[col][row]);
            }
        }

        // output result image
        outputImage(outFile, result, width, height);

        // delete images to avoid memory leaks
        unsigned int tmpWidth;
        unsigned int tmpHeight;

        tmpWidth = width;
        tmpHeight = height;
        deleteImage(img1, tmpWidth, tmpHeight);

        tmpWidth = width;
        tmpHeight = height;
        deleteImage(img2, tmpWidth, tmpHeight);

        tmpWidth = width;
        tmpHeight = height;
        deleteImage(img3, tmpWidth, tmpHeight);

        deleteImage(result, width, height);
    }
    catch (std::invalid_argument& e) {
        cout << "ERROR, " << e.what() << endl;
    }
    catch (std::bad_alloc& e) {
        cout << "ERROR, unable to allocate memory for 2d array " << e.what() << endl;
    }
    catch (...) {
        cout << "ERROR, encountered an unexpected error!" <<endl;
    }

    return 0;
}
