#include "LinkedList.h"

using std::cout, std::endl;

void printTest(std::string label, const LinkedList& l) {
    cout << label << endl;
    l.print();
    cout << endl;
}

int main() {
    LinkedList ll;
    printTest("ll: constructor", ll);

    ll.insertBack(8);
    printTest("ll: insertBack(8)", ll);

    ll.insertFront(3);
    printTest("ll: insertFront(3)", ll);

    LinkedList ll2(ll);
    printTest("ll2: copy ll", ll2);

    ll.insertBack(7);
    printTest("ll: insertBack(7)", ll);
    printTest("ll2:", ll2);

    ll2 = ll;
    printTest("ll2 = ll1", ll2);

    ll.clear();
    printTest("ll: clear", ll);
    printTest("ll2:", ll2);
}
