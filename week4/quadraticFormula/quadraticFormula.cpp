#include <iostream>
#include <cmath> //provides common math functions like sqrt and fabs

using std::cout, std::cin, std::endl; 

// Function declarations
void outputEquation(double a, double b, double c);


/*
Pseudocode goes here.
*/

int main() {
    // Prompt user for coefficients a, b, c
    cout << "Input coefficients a, b, and c for your equation: ";
    double a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    // Output equation ax^2 + bx + c = 0
    outputEquation(a, b, c);

    // TODO
}


void outputEquation(double a, double b, double c) {
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}
