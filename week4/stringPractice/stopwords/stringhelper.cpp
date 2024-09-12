#include <iostream>
#include "stringhelper.h"

using std::cout, std::cin, std::endl, std::string;

size_t countString(string searchString, string source) {
    size_t stringCount = 0;
    size_t sourceIndex = source.find(searchString); // index to first location of searchstring
    size_t searchLength = searchString.length();
    while (sourceIndex != string::npos) {
        // if spaces on both sides since we don't want spiffy to become spfy when 'if' is removed
        if ((sourceIndex == 0 || isspace(source.at(sourceIndex-1))) // it is the first word in the string or there is a space before it
            && // AND
           (sourceIndex+searchLength >= source.length() || isspace(source.at(sourceIndex+searchLength)))) { // it is the last word in the string or there is a space after
                stringCount++;
        }
        sourceIndex = source.find(searchString, sourceIndex+searchLength); // get the next index of the next occurrence by starting search after previous occurrence
    }
    return stringCount;
}

string removeString(string removeString, string source) {
    size_t removeCount = 0;
    size_t removeLength = removeString.length();
    size_t index = source.find(removeString); // get location of first occurrence
    while (index != string::npos) { // While there is an occurence of the word in the string
       size_t offset = removeLength;
       if ((index == 0 || isspace(source.at(index-1))) // it is the first word in the string or there is a space before it 
            && // AND
           (index+removeLength >= source.length() || isspace(source.at(index+removeLength)))) { // it is the last word in the string or there is a space after
                source.erase(index, removeLength);
                removeCount++;
                offset = 0;
        }
        // else it was not a word and offset will skip over that string in the next search

        index = source.find(removeString, index+offset); // update to index of next occurence
    }
    cout << "Removed '" << removeString << "' " << removeCount << " times" << endl;
    return source;
}