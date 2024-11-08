#include "LinkedList.h"

void LinkedList::clear() {
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
    // head is nullptr when loop exits

    tail = nullptr;
}


void LinkedList::insertFront(const int& data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode;
    }
}


void LinkedList::insertBack(const int& data) {
    Node* newNode = new Node(data); // newNode->next is set to nullptr in its constructor
    if (tail == nullptr) { // empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}


void LinkedList::print(std::ostream& os) const {
    Node* cur = head;
    if (cur == nullptr) {
        os << "Empty List!";
    }
    while (cur != nullptr) {
        os << cur->data << " ";
        cur = cur->next;
    }
    os << std::endl;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
    ll.print(os);
    return os;
}
