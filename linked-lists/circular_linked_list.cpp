// circular_linked_list.cpp
// This file demonstrates a circular singly linked list implementation using pointers in C++.
// The list supports insertion at the end, deletion by value, and display operations.

#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert a value at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }

    // Delete the first node with the given value
    void remove(int value) {
        if (head == nullptr) return;
        Node* current = head;
        Node* prev = nullptr;
        do {
            if (current->data == value) {
                if (prev != nullptr) {
                    prev->next = current->next;
                    if (current == head) head = current->next;
                } else {
                    // Removing the head node
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (head == head->next) {
                        // Only one node
                        delete head;
                        head = nullptr;
                        return;
                    }
                    last->next = head->next;
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                    return;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
    }

    // Display the list contents
    void display() {
        if (head == nullptr) {
            cout << "Circular linked list is empty." << endl;
            return;
        }
        cout << "Circular linked list: ";
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(100);
    list.insert(200);
    list.insert(300);

    list.display();

    list.remove(200);
    list.display();

    return 0;
}