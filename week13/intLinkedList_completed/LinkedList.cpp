#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr) {
    Node* cur = source.head;
    while(cur != nullptr) {
        insertBack(cur->data);
        cur = cur->next;
    }
}


LinkedList& LinkedList::operator=(const LinkedList& source) {
    clear();
    Node* cur = source.head;
    while(cur != nullptr) {
        insertBack(cur->data);
        cur = cur->next;
    }
    return *this;
}


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


void LinkedList::insertAfter(const int& valueToInsert, const int& valueToLookFor) {
    bool found = false;
    Node* cur = head;
    while(cur != nullptr && !found) {
        if(cur->data == valueToLookFor) {
            found = true;
            Node* newNode = new Node(valueToInsert);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        cur = cur->next;
    }
}


void LinkedList::remove(const int& value) {
    // check if empty list
    if(head == nullptr) {
        return;
    }

     // check case that list only has 1 element
    if(head == tail) {
        if(head->data == value) {
            delete head;
            head = tail = nullptr;
        }
        return;
    }

    // check case that head matches
    if(head->data == value) {
        Node* removeNode = head;
        head = head->next;
        delete removeNode;
        return;
    }

    // check if next element matches, if so remove it
    // make sure to update tail if you remove the last item
    Node* cur = head;
    while(cur->next != nullptr) {
        if(cur->next->data == value) {
            Node* removeNode = cur->next;
            cur->next = cur->next->next;
            delete removeNode;
            if (cur->next == nullptr) {
                tail = cur;
            }
            return;
        } else {
            cur = cur->next;
        }
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


bool LinkedList::contains(const int& value) const {
    Node* cur = head;
    while(cur != nullptr) {
        if(cur->data == value) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}
