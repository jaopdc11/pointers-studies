// memory_leak_example.cpp
// This file demonstrates a simple example of a memory leak in C++ and how to avoid it.
// Memory leaks happen when dynamically allocated memory is not properly freed.

#include <iostream>

using namespace std;

void memoryLeak() {
    int* leak = new int[100]; // Memory allocated but never freed
    leak[0] = 42;
    cout << "Leaked value: " << leak[0] << endl;
    // No delete[] leak; // This causes a memory leak
}

void noMemoryLeak() {
    int* safe = new int[100];
    safe[0] = 99;
    cout << "Safe value: " << safe[0] << endl;
    delete[] safe; // Properly freeing memory
}

int main() {
    cout << "Demonstrating memory leak:" << endl;
    memoryLeak();

    cout << "\nDemonstrating proper memory management:" << endl;
    noMemoryLeak();

    return 0;
}