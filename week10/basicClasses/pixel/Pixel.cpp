#include "Pixel.h"

void Pixel::print(std::ostream& _out) const {
    _out << red << " " << green << " " << blue;
}
