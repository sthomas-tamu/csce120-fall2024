#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::vector;

int main() {
    //vector of vectors with doubles
    vector<vector<double> > vd;
  
    //put data in the vector
    double temp = 1; //used to create data values to put in 
    for (size_t i=0; i<5; ++i) {
        vd.push_back(vector<double>()); //add a new vector to the list
        for (size_t j=0; j<5; ++j) {
            temp *= 1.15;
            vd.at(i).push_back(temp); //add a new element to the vector
        }
    }
  
    //print out the vector of vectors
    for (size_t i=0; i<vd.size(); ++i) {
        for (size_t j=0; j<vd.at(i).size(); ++j) {
            cout << vd.at(i).at(j) << " "; //can access like a 2D array, just using at() instead of []
        }
        cout << endl;
    }

    cout << endl;
  
    //vector of vectors with char, 3 rows of 4 'z'
    vector<vector<char> > vc (3, vector<char>(4, 'z'));
  
    //print out the vector of vectors
    for (size_t i=0; i<vc.size(); ++i) {
        for (size_t j=0; j<vc.at(i).size(); ++j) {
            cout << vc.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
