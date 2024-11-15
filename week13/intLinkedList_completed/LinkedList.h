#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
    Node* head;
    Node* tail;

  public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    LinkedList(const LinkedList&);
    ~LinkedList() { clear(); }
    LinkedList& operator=(const LinkedList&);

    void clear();

    void insertFront(const int& val);
    void insertBack(const int& val);
    void insertAfter(const int& valueToInsert, const int& valueToLookFor);

    void remove(const int& value);

    void print(std::ostream& = std::cout) const;

    bool contains(const int& value) const;
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif
