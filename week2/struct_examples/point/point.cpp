#include <iostream>

using std::cout, std::endl;

// define a struct
struct Point {
    double x = 0; //the x coordinate, initialized to 0
    double y = 0; //the y coordinate, initialized to 0
};

int main() {
    // declare / define a struct variable
    Point p;

    // assign values to members of the struct
    p.x = 1.0;
    p.y = 2.5;    
    
    // access members of the struct
    cout << "p: " << p.x << " " << p.y << endl;


    // another way to declare a struct variable and set its members
    Point q;
    q = {-4, 3.3};
    cout << "q: " << q.x << " " << q.y << endl;


    // yet another way, all on 1 line
    Point r({10, -10});
    cout << "r: " << r.x << " " << r.y << endl;
}
