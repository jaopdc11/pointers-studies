// dynamic_memory_allocation.cpp
// This file demonstrates dynamic memory allocation in C++ using new and delete.
// Dynamic memory allocation allows you to request memory during runtime, which is useful for flexible data structures.

#include <iostream>

using namespace std;

int main() {
    cout << "Dynamic Memory Allocation Example" << endl;
    cout << "--------------------------------" << endl;

    // Allocate memory for a single integer
    int* singleInt = new int;
    *singleInt = 42;
    cout << "Value of dynamically allocated integer: " << *singleInt << endl;

    // Allocate memory for an array of integers
    int size = 5;
    int* array = new int[size];

    // Initialize and print the array
    for (int i = 0; i < size; ++i) {
        array[i] = (i + 1) * 10;
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    // Free the allocated memory
    delete singleInt;      // Free single integer
    delete[] array;        // Free array

    // Example of memory leak (do not do this in real code!)
    int* leak = new int[100];
    // Memory allocated to 'leak' is never freed, causing a memory leak

    cout << "If you don't use delete, you will have a memory leak!" << endl;

    return 0;
}