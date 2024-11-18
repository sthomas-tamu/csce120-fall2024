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

void LinkedList::print(std::ostream& os) const {
    Node* cur = head;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->next;
    }
}

/*
void LinkedList::printReverse(std::ostream& os) const {
}

void LinkedList::insertFront(const char& val) {
}
*/

void LinkedList::insertBack(const char& val) {
    Node* newNode = new Node(val);
    if(head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;   
    }
}

/*        
void LinkedList::insertAfter(const char& valToAdd, const char& valToFind) {
}

void LinkedList::insertBefore(const char& valToAdd, const char& valToFind) {
}

void LinkedList::remove(const char& c) {
}

bool LinkedList::hasChar(const char& c) const {
}
*/

std::ostream& operator<<(std::ostream& os, const LinkedList& source) {
    source.print(os);
    return os;
}

