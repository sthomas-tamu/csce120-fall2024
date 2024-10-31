#ifndef _COORDS_H_
#define _COORDS_H_

#include <ostream>

class Coords {
    double x, y;

  public:
    Coords() : x(0.0), y(0.0) {}
    Coords(double _x, double _y) : x(_x), y(_y) {}

    double getX() const { return x; }
    double getY() const { return y; }
};

std::ostream& operator<<(std::ostream& os, const Coords& coord) {
    os << "(" << coord.getX() << ", " << coord.getY() << ")";
    return os;
}

#endif
