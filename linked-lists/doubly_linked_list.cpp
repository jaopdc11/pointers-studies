// doubly_linked_list.cpp
// This file demonstrates a doubly linked list implementation using pointers in C++.
// The list supports insertion at the end, deletion by value, and display operations.

#include <iostream>

using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert a value at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Delete the first node with the given value
    void remove(int value) {
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }
        if (current == nullptr) return;
        if (current->prev != nullptr)
            current->prev->next = current->next;
        else
            head = current->next;
        if (current->next != nullptr)
            current->next->prev = current->prev;
        delete current;
    }

    // Display the list contents
    void display() {
        cout << "Doubly linked list (forward): ";
        Node* current = head;
        Node* last = nullptr;
        while (current != nullptr) {
            cout << current->data << " ";
            last = current;
            current = current->next;
        }
        cout << endl;

        cout << "Doubly linked list (backward): ";
        current = last;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    list.display();

    list.remove(2);
    list.display();

    return 0;
}