// dynamic_queue.cpp
// This file demonstrates a dynamic queue implementation using pointers in C++.
// The queue supports enqueue, dequeue, and display operations.

#include <iostream>

using namespace std;

// Node structure for the queue
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue a value into the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into the queue." << endl;
    }

    // Dequeue a value from the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
            return;
        }
        Node* temp = front;
        cout << "Dequeued " << temp->data << " from the queue." << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Display the queue contents
    void display() {
        cout << "Queue contents (front to rear): ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;

    queue.enqueue(5);
    queue.enqueue(15);
    queue.enqueue(25);

    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}