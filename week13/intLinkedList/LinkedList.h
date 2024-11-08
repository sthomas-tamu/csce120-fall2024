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
    // also need Copy Constructor and Copy Assignment
    ~LinkedList() { clear(); }

    void clear();

    void insertFront(const int& val);
    void insertBack(const int& val);

    void print(std::ostream& = std::cout) const;
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif