#include "Complex.h"

#include <sstream>

std::string Complex::to_string() const {
    std::ostringstream oss;
    oss << real;
    if (imag < 0) {
        oss << " - " << (-1*imag);
    } else {
        oss << " + " << imag;
    }
    oss << "i";
    return oss.str();
}


Complex& Complex::operator=(const Complex& other) {
    this->real = other.real;
    this->imag = other.imag;
    return *this;
}



Complex& Complex::operator+=(const Complex& other) {
    this->real += other.real;
    this->imag += other.imag;
    return *this;
}


Complex Complex::operator-() const {
    Complex c(-1*this->real, -1*this->imag);
    return c;
}

