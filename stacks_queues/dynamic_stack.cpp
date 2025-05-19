// dynamic_stack.cpp
// This file demonstrates a dynamic stack implementation using pointers in C++.
// The stack supports push, pop, and display operations.

#include <iostream>

using namespace std;

// Node structure for the stack
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}

    // Push a value onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Pop a value from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        cout << "Popped " << temp->data << " from the stack." << endl;
        top = top->next;
        delete temp;
    }

    // Display the stack contents
    void display() {
        cout << "Stack contents (top to bottom): ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    stack.pop();
    stack.display();

    return 0;
}