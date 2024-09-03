#include <iostream>

#include "debug.h"

using std::cout, std::endl;

int increment(int val) {
  DEBUG("val = " << val);
  val++;
  return val;
}

int main() {
  cout << "Showing that variables are passed by value" << endl;

  int x = 5;
  cout << "x is " << x << endl;
  DEBUG("attempting to increment x");
  increment(x);
  cout << "after increment(x), x is still " << x << endl;

  DEBUG("attempting to increment x again, but this time using the return value to assign");
  x = increment(x);
  cout << "after assigning x equal to increment(x), x is now " << x << endl;
};
