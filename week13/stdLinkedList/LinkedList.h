#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    char letter;
    Node* next;
    Node* prev;
    Node(int letter) : letter(letter), next(nullptr), prev(nullptr) {}
};

class LinkedList {
    Node* head;
    Node* tail;

    Node* find(const char& c);

  public:
    //constructors & deconstructor
    LinkedList() : head(nullptr), tail(nullptr) {}
    LinkedList(const std::string&); // copy std::string
    LinkedList(const char*); // copy c-string
    LinkedList(const LinkedList&);
    ~LinkedList();

    LinkedList& operator=(const LinkedList&);

    void print(std::ostream& = std::cout) const;
    //void printReverse(std::ostream& = std::cout) const;
    
    // setters and getters
    char peekFront() const { return head->letter; }
    char peekBack() const { return tail->letter; }
    
    //void insertFront(const char& val);
    void insertBack(const char& val);
    
    //void insertAfter(const char& valToAdd, const char& valToFind);
    //void insertBefore(const char& valToAdd, const char& valToFind);

    //void remove(const char&);

    //bool hasChar(const char& c) const;
};

std::ostream& operator<<(std::ostream&, const LinkedList&);

#endif
