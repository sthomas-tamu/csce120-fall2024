#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex {
  private:
    double real, imag;

  public:
    Complex();
    Complex(double _real);
    Complex(double _real, double _imag);

    double getReal() const;
    void setReal(double value);

    double getImaginary() const;
    void setImaginary(double value);
};

#endif
