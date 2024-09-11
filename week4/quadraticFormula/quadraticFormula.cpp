#include <iostream>
#include <cmath> //provides common math functions like sqrt and fabs

using std::cout, std::cin, std::endl; 

// Struct for returning error codes
struct Result {
    double root1_value, root2_value;
    bool root1_valid, root2_valid;
};

// Function declarations
void outputEquation(double a, double b, double c);

Result solveLinear(double b, double c);
Result solveQuadratic(double a, double b, double c);

bool checkRoot(double a, double b, double c, double root);

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
        if(root.root1_valid) {
            cout << "The root is " << root.root1_value << endl;
            cout << "Checking the root: ";
            if (checkRoot(a, b, c, root.root1_value))
                cout << "true!" << endl;
            else
                cout << "false :(" << endl;
        } else {
            cout << "Error! Not a valid equation" << endl;
        }
    } else {
        //solve quadratic version
        Result roots;
        roots = solveQuadratic(a, b, c);

        if(roots.root1_valid) {
            cout << "Root is " << roots.root1_value << endl;
            cout << "Checking the root: ";
            if (checkRoot(a, b, c, roots.root1_value))
                cout << "true!" << endl;
            else
                cout << "false :(" << endl;
            if(roots.root2_valid) {
                cout << "Root is " << roots.root2_value << endl;
                cout << "Checking the root: ";
                   if (checkRoot(a, b, c, roots.root2_value))
                        cout << "true!" << endl;
                    else
                        cout << "false :(" << endl;
            }
        } else {
            cout << "Error, roots complex " << endl;
            //instead of reporting an error, could create a solveComplex function
            /*

            */
        }
    }

    return 0;
}


void outputEquation(double a, double b, double c) {
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

Result solveLinear(double b, double c) {
    Result result;
    if (b == 0) {
        result.root1_value = 0;
        result.root1_valid = false;
    } else {
        result.root1_value = -c / b;
        result.root1_valid = true;
    }

    //will never have a second root
    result.root2_value = 0;
    result.root2_valid = false;

    return result;
}

Result solveQuadratic(double a, double b, double c) {
    /*
    compute descriminant
    if (discriminant is >= 0)
      compute roots using formula
    else
      report complex root
    */

   Result roots;
   roots.root1_valid = false;
   roots.root2_valid = false;
   roots.root1_value = 0;
   roots.root2_value = 0;
   
   double descriminant = b*b - 4*a*c;
   cout << "Descriminant is " << descriminant << endl;

   if(descriminant < 0) { // complex root
        return roots;
   } else { // real root
        roots.root1_value = (-b + sqrt(descriminant))/(2*a);
        roots.root1_valid = true;

        //only have root2 if descriminant is not 0
        if(descriminant != 0) {
            roots.root2_value = (-b - sqrt(descriminant))/(2*a);
            roots.root2_valid = true;
        } else {
            roots.root2_value = 0;
            roots.root2_valid = false;
        }
   }

   return roots;
}

bool checkRoot(double a, double b, double c, double root) {
    double value = a*root*root + b*root + c;
    return (value == 0);
}
