#include "Pixel.h"

#include <stdexcept>


// Constructors
Pixel::Pixel (unsigned short _red, unsigned short _green, unsigned short _blue) : 
    red(_red), green(_green), blue(_blue) {
        if (red > 255 || green > 255 || blue > 255) {
            throw std::invalid_argument("Color values must be 255 or less.");
        }
    }


// Setters
void Pixel::setRed(unsigned short _red) {
    if (_red > 255) {
        throw std::invalid_argument("Color values must be 255 or less.");
    }
    red = _red;
}

void Pixel::setGreen(unsigned short _green) {
    if (_green > 255) {
        throw std::invalid_argument("Color values must be 255 or less.");
    }
    green = _green;
}

void Pixel::setBlue(unsigned short _blue) {
    if (_blue > 255) {
        throw std::invalid_argument("Color values must be 255 or less.");
    }
    blue = _blue;
}


// Operators

// implement operator==
bool Pixel::operator==(const Pixel& other) {
}

// implement operator=
Pixel& Pixel::operator=(const Pixel& other) {
}

// implement operator+
Pixel Pixel::operator+(const Pixel& other) {
}

// implement operator-
Pixel& Pixel::operator-() {
}

