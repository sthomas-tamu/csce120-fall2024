#include <iostream>

using std::cout, std::endl, std::string;

struct Coordinates {
    double x = 0;
    double y = 0;
};


// define a nested struct
struct City {
    string name = "";
    string state = "";
    Coordinates location;
};


int main() {
    // declare a nested struct variable
    Coordinates coords({30.2672, -97.7431});
    City capital({"Austin", "TX", coords});
    
    cout << "The state capital is in ";
    cout << capital.name << ", " << capital.state << " located at (" << capital.location.x << ", " << capital.location.y << ")";
    cout << "." << endl;
}
