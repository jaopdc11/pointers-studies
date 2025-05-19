// pointers_and_arrays.cpp
// This file demonstrates the relationship between pointers and arrays in C++.
// Arrays and pointers are closely related, but not the same. This example shows how to use pointers to access array elements.

#include <iostream>

using namespace std;

int main() {
    int numbers[5] = {5, 10, 15, 20, 25};

    // The name of the array 'numbers' acts as a pointer to its first element
    int* ptr = numbers;

    cout << "Pointers and Arrays Example" << endl;
    cout << "--------------------------" << endl;

    // Accessing array elements using array indexing
    cout << "Accessing with array indexing:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }

    cout << endl;

    // Accessing array elements using pointer arithmetic
    cout << "Accessing with pointer arithmetic:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "*(ptr + " << i << ") = " << *(ptr + i) << endl;
    }

    cout << endl;

    // Modifying array elements using pointers
    cout << "Modifying array elements using pointers:" << endl;
    for (int i = 0; i < 5; ++i) {
        *(ptr + i) += 1; // Increment each element by 1
        cout << "numbers[" << i << "] after increment = " << numbers[i] << endl;
    }

    cout << endl;

    // Demonstrating that arrays and pointers are not exactly the same
    cout << "Size of numbers (array): " << sizeof(numbers) << " bytes" << endl;
    cout << "Size of ptr (pointer): " << sizeof(ptr) << " bytes" << endl;

    return 0;
}