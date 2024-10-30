#ifndef _COMPLEX_H_
#define _COMPLEX_H_

#include <string>

class Complex {
  private:
    double real, imag;

  public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double _real) : real(_real), imag(0.0) {}
    Complex(double _real, double _imag) : real(_real), imag(_imag) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {}

    double getReal() const { return real; }
    void setReal(double value) { real = value; }

    double getImaginary() const { return imag; }
    void setImaginary(double value) { imag = value; }

    std::string to_string() const;

    bool operator==(const Complex& other) const { return ((this->real == other.real) && (this->imag == other.imag)); }
    Complex& operator=(const Complex& other);
    Complex& operator+=(const Complex& other);
    Complex operator-() const;
};

#endif
