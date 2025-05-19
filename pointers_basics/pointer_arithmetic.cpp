// pointer_arithmetic.cpp
// This file demonstrates basic pointer concepts and pointer arithmetic in C++.
// Pointer arithmetic allows you to move through memory addresses, which is especially useful when working with arrays.

#include <iostream>

using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int* ptr = numbers; // Pointer to the first element of the array

    cout << "Pointer Arithmetic Example" << endl;
    cout << "-------------------------" << endl;

    // Accessing array elements using pointer arithmetic
    for (int i = 0; i < 5; ++i) {
        cout << "Address of numbers[" << i << "]: " << (ptr + i) << endl;
        cout << "Value at numbers[" << i << "] using pointer: " << *(ptr + i) << endl;
    }

    cout << endl;

    // Demonstrating increment and decrement of pointers
    cout << "Original pointer address: " << ptr << endl;
    ptr++; // Move to the next integer in the array
    cout << "Pointer after increment (ptr++): " << ptr << " (value: " << *ptr << ")" << endl;
    ptr--; // Move back to the original position
    cout << "Pointer after decrement (ptr--): " << ptr << " (value: " << *ptr << ")" << endl;

    cout << endl;

    // Difference between two pointers
    int* ptr_end = &numbers[4];
    cout << "Distance between ptr_end and ptr: " << (ptr_end - ptr) << " elements" << endl;

    return 0;
}