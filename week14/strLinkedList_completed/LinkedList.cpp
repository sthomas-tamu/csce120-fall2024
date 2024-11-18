#include <iostream>
#include "LinkedList.h"

using std::cout, std::endl;

LinkedList::LinkedList(const std::string& source) : head(nullptr), tail(nullptr) {
    for (size_t i=0; i<source.size(); ++i) {
        insertBack(source.at(i));
    }
}

LinkedList::LinkedList(const char* source) : head(nullptr), tail(nullptr) {
    size_t index = 0;
    while (source[index] != '\0') {
        insertBack(source[index]);
        index++;
    }
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
    const Node* cur = source.head;
    while(cur != nullptr) {
        insertBack(cur->letter);
        cur = cur->next;
    }
}

LinkedList::~LinkedList() {
    Node* cur = tail;
    while(cur != head) {
        cur = cur->prev;
        delete cur->next; 
    }
    if (head != nullptr) {
        delete head;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
    const Node* cur = source.head;
    while(cur != nullptr) {
        insertBack(cur->letter);
        cur = cur->next;
    }
    return *this;
}

Node* LinkedList::find(const char& c) {
    Node* cur = head;
    while (cur != nullptr && cur->letter != c) {
        cur = cur->next;
    }
    return cur;
}

void LinkedList::print(std::ostream& os) const {
    Node* cur = head;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->next;
    }
}

void LinkedList::printReverse(std::ostream& os) const {
    Node* cur = tail;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->prev;
    }
}

void LinkedList::insertFront(const char& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // empty list
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::insertBack(const char& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void LinkedList::insertAfter(const char& valToAdd, const char& valToFind) {
    Node* newNode = new Node(valToAdd);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        Node* cur = find(valToFind);
        if (cur == nullptr) { // if not found, insert at end
            cur = tail;
        }

        // update newNode next and prev
        newNode->next = cur->next;
        newNode->prev = cur;

        // update after insertion
        if (cur->next == nullptr) { // new tail
            tail = newNode;
        } else {
            cur->next->prev = newNode;
        }

        // update before insertion
        cur->next = newNode;
    }
}

void LinkedList::insertBefore(const char& valToAdd, const char& valToFind) {
    Node* newNode = new Node(valToAdd);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        Node* cur = find(valToFind);
        if (cur == nullptr) { // if not found, insert at beginning
            cur = head;
        }
 
        // update newNode next and prev
        newNode->next = cur;
        newNode->prev = cur->prev;

        // update before insertion
        if (cur == head) { // cur->prev == nullptr
            head = newNode;
        } else {
            cur->prev->next = newNode;
        }

        // update after insertion
        cur->prev = newNode;
    }
}

void LinkedList::remove(const char& c) {
    Node* cur = find(c);
    if (cur != nullptr) {
        if (cur == tail) {
            tail = cur->prev;
        } else {
            cur->next->prev = cur->prev;
        }
        if (cur == head) {
            head = cur->next;
        } else {
            cur->prev->next = cur->next;
        }
    }
    delete cur;
}

bool LinkedList::hasChar(const char& c) const {
    const Node* cur = head;
    while(cur != nullptr) {
      if(cur->letter == c) {
          return true;
      }
      cur = cur->next;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& source) {
    source.print(os);
    return os;
}

