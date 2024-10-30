#include "Pixel.h"

#include <stdexcept>


// Constructors
Pixel::Pixel(unsigned short _red, unsigned short _green, unsigned short _blue) : 
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

bool Pixel::operator==(const Pixel& other) const {
    return (this->red == other.red &&
            this->green == other.green &&
            this->blue == other.blue);
}

Pixel& Pixel::operator=(const Pixel& other) {
    this->red = other.red;
    this->green = other.green;
    this->blue = other.blue;
    return *this;
}

Pixel Pixel::operator+(const Pixel& other) {
    Pixel newColor;
    newColor.red = (this->red + other.red)/2;
    newColor.green = (this->green + other.green)/2;
    newColor.blue = (this->blue + other.blue)/2;
    return newColor;
}

Pixel& Pixel::operator-() {
    this->red = 255 - this->red;
    this->green = 255 - this->green;
    this->blue = 255 - this->blue;
    return *this;
}


std::ostream& operator<<(std::ostream& os, const Pixel& p) {
    os << "{";
    os << p.getRed() << ", "; 
    os << p.getGreen() << ", "; 
    os << p.getBlue();
    os << "}";
    return os; 
}
