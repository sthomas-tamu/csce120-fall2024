#include <iostream>
#include <cmath> //provides common math functions like sqrt and fabs

using std::cout, std::cin, std::endl; 

// Struct for returning error codes
struct Result {
    double value;
    bool valid;
};

// Function declarations
void outputEquation(double a, double b, double c);

Result solveLinear(double b, double c);


int main() {
    // Prompt user for coefficients a, b, c
    cout << "Input coefficients a, b, and c for your equation: ";
    double a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    // Output equation ax^2 + bx + c = 0
    outputEquation(a, b, c);

    if (a == 0) {
        //solve linear version
        Result root = solveLinear(b, c);
        if(root.valid) {
            cout << "The root is " << root.value << endl;
        } else {
            cout << "Error! Not a valid equation" << endl;
        }
    } else {
        //solve quadratic version
        cout << "TODO: implement quadratic solver" << endl;
    }

    return 0;
}


void outputEquation(double a, double b, double c) {
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

Result solveLinear(double b, double c) {
    Result result;
    if (b == 0) {
        result.value = 0;
        result.valid = false;
    } else {
        result.value = -c / b;
        result.valid = true;
    }
    return result;
}
