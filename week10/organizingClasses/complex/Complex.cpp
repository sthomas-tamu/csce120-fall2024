#include "Complex.h"

Complex::Complex() : real(0), imag(0) {}
Complex::Complex(double _real) : real(_real), imag(0) {}
Complex::Complex(double _real, double _imag) : real(_real), imag(_imag) {}

double Complex::getReal() const {
    return real;
}

void Complex::setReal(double value) {
    real = value;
}

double Complex::getImaginary() const {
    return imag;
}

void Complex::setImaginary(double value) {
    imag = value;
}
