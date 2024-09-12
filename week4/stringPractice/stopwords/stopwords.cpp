#include <iostream>
#include "stringhelper.h"

using std::string, std::cout, std::cin, std::endl;

int main() {
    // assumptions, everything is all lower case

    //string stopwords = "a,an,because,for,that,the,they,to,were"; // for debugging
    string stopwords = "a,able,about,across,after,all,almost,also,am,among,an,and,any,are,as,at,be,because,been,but,by,can,cannot,could,dear,did,do,does,either,else,ever,every,for,from,get,got,had,has,have,he,her,hers,him,his,how,however,i,if,in,into,is,it,its,just,least,let,like,likely,may,me,might,most,must,my,neither,no,nor,not,of,off,often,on,only,or,other,our,own,rather,said,say,says,she,should,since,so,some,than,that,the,their,them,then,there,these,they,this,tis,to,too,twas,us,wants,was,we,were,what,when,where,which,while,who,whom,why,will,with,would,yet,you,your";
    // from https://www.textfixer.com/tutorials/common-english-words.txt

    string text = "an elephant told a rabbit that they were going to the store for a vacation just because";
    /*
    cout << "Enter text to process: ";
    getline(cin, text);
    */

    cout << "Original string: " << endl;
    cout << text << endl;

    // TODO: go through stopwords and remove from the file
    size_t stopwordIndex = 0; // keeps track of where in the stopwords we are
    while (stopwordIndex < stopwords.length()) {
        size_t commaIndex = stopwords.find(",", stopwordIndex); // get index of first comma
        size_t length = string::npos; // initialize to value used if not found
        if (commaIndex != string::npos) { // if we found a comma
            length = commaIndex - stopwordIndex; // calculate length of the stopword to use in .substr method
        }
        string stopword = stopwords.substr(stopwordIndex, length); // extract the stopword
        size_t stopwordCount = countString(stopword, text); // count the number of stopwords in the string
        cout << "'" << stopword << "': " << stopwordCount << endl;
        text = removeString(stopword, text); // remove all of the instances
        if (commaIndex != string::npos) { // set up to process next stopword
            stopwordIndex += length + 1; // lenght of the stopword plus one for the comma after it
        }
        else { // set up to exit loop
            stopwordIndex = string::npos; // stopwords.length() // forces us out of the loop
        }
        // cout << "stopwordIndex: " << stopwordIndex << endl;
        // stopwordIndex = stopwordIndex + length + 1
    }
    // Output each stopword and how many instances to standard out
    cout << "Updated string: " << endl;
    cout << text << endl;
}
