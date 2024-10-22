#ifndef _PIXEL_H_
#define _PIXEL_H_

#include <stdexcept>
#include <iostream>
#include <sstream>

class Pixel {

  private: 
    // Data Members
    unsigned short red, green, blue;

  public:
    
    // Constructors
    Pixel(unsigned short _red, unsigned short _green, unsigned short _blue) :
      red(_red), green(_green), blue(_blue) {
          if(red > 255 || green > 255 || blue > 255) {
              std::ostringstream errorMsg;
              errorMsg << "Invalid color (" << red << " " << green << " " << blue << "), all colors must be between 0 and 255";
              throw std::invalid_argument(errorMsg.str());
          }
      };

    Pixel() : 
      red(0), green(0), blue(0) {}

    Pixel(const Pixel& p) : 
      red(p.red), green(p.green), blue(p.blue) {}

    // Member Functions
    void print(std::ostream& _out) const;
};

#endif
