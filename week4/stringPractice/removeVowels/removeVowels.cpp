#include <iostream>
#include <ctime>
#include <string>

using std::cout, std::cin, std::endl, std::string;

// Goal: Replace all occurrances of vowels with a random symbol

// string documentation:
// - http://www.cplusplus.com/reference/string/string/
// - https://en.cppreference.com/w/cpp/string/basic_string

int main() {
  srand(time(NULL)); // seed random number generator with current time
  
  string text; // text to transform
  string vowels = "aeiouAEIOU"; // not including 'y' or 'Y'
  string symbols = "@#$%^&*~"; // set of symbols for replacement
  
  cout << "Enter phrase: ";
  getline(cin, text); // get entire line including spaces.
  
  // add code to replace vowels with random symbols from set
  for (size_t i=0; i<vowels.size(); ++i) { // for each vowel, find every occurance and replace it with a symbol
    size_t position = 0; // start at the beginning of the text
    do { // scan until reach the end of the text
      position = text.find_first_of(vowels.at(i));
      if (position != string::npos) { // replace character
        size_t index = rand() % symbols.size();
        text.at(position) = symbols.at(index);
      }
    } while (position != string::npos);
  }
  
  cout << "Your modified phrase: " << text << endl;
}
