#include <iostream>
#include "LinkedList.h"

using std::cout, std::endl;

void printTest(std::string label, const LinkedList& l) {
    cout << label << ": ";
    cout << '"' << l << '"';
    cout << "\t(reverse: '"; l.printReverse(); cout << "')";
    cout << endl;
}

int main() {
    LinkedList s1;
    printTest("s1: default construct", s1);
    cout << endl;
    
    s1.insertFront('a');
    s1.insertBack('c');
    printTest("s1: add 'a' to front and 'c' back", s1);
    cout << endl;
    
    LinkedList s2("hello");
    printTest("s2: construct from a c-string", s2);
    cout << endl;
 
    s2.insertAfter('=','o');
    printTest("s2: insert = after o", s2);
    s2.insertAfter('k', 'z');
    printTest("s2: insert k after z", s2);
    s2.insertBefore('?','h');
    printTest("s2: insert ? before W", s2);
    s2.insertBefore('-', 'z');
    printTest("s2: insert - before z",s2);
    cout << endl;

    std::string temps = "World";
    LinkedList s3(temps);
    printTest("s3: construct from std::string", s3);
    cout << endl;

    cout << "s3 has r: " << std::boolalpha << s3.hasChar('r') << endl;
    cout << "s3 has z: " << std::boolalpha << s3.hasChar('z') << endl;
    cout << endl;
    
    s3.remove('W');
    printTest("s3: remove W", s3);
    s3.remove('z');
    printTest("s3: remove z", s3);
    s3.remove('d');
    printTest("s3: remove d", s3);
    s3.remove('l');
    printTest("s3: remove l", s3);
    s3.remove('r');
    printTest("s3: remove r", s3);
    s3.remove('o');
    printTest("s3: remove o", s3);
}
