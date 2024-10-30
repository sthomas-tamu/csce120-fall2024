#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

class Pixel {
  private: // optional here since classes are private by default
    unsigned short red;
    unsigned short green;
    unsigned short blue;

  public:
    // constructors
    Pixel(unsigned short red, unsigned short green, unsigned short blue);
    Pixel(const Pixel& p) : red(p.red), green(p.green), blue(p.blue) {} // copy constructor
    Pixel() : red(0), green(0), blue(0) {} // default constructor

    // getter and setter methods
    unsigned short getRed() const { return red; }
    void setRed(unsigned short _red);

    unsigned short getGreen() const { return green; }
    void setGreen(unsigned short _green);

    unsigned short getBlue() const { return blue; }
    void setBlue(unsigned short _blue);

    // operators
    bool operator==(const Pixel& other) const;
    Pixel& operator=(const Pixel& other);
    Pixel operator+(const Pixel& other); // for pixels, addition should average (keeps pixels in valid range)
    Pixel& operator-(); // unary version, computes the negative (opposite) pixel
};

std::ostream& operator<<(std::ostream& os, const Pixel& p);

#endif
