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

    cout << "ll2 contains 8: " << std::boolalpha << ll2.contains(8) << endl;
    cout << "ll2 contains 0: " << std::boolalpha << ll2.contains(0) << endl;

    printTest("ll2:", ll2);

    ll2.insertAfter(-1, 0);
    printTest("ll2 attempt insert -1 after 0:", ll2);

    ll2.insertAfter(-1, 8);
    printTest("ll2 attempt insert -1 after 8:", ll2);

    ll2.remove(0);
    printTest("remove 0 from ll2:", ll2);

    ll2.remove(8);
    printTest("remove 8 from ll2:", ll2);

    ll2.remove(3);
    printTest("remove 3 from ll2:", ll2);

    ll2.remove(7);
    printTest("remove 7 from ll2:", ll2);
}
