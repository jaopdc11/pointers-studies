// pointers_to_functions.cpp
// This file demonstrates how to use pointers to functions in C++.
// Function pointers allow you to pass functions as arguments, store them in variables, and call them dynamically.

#include <iostream>

using namespace std;

// A simple function that adds two integers
int add(int a, int b) {
    return a + b;
}

// A simple function that multiplies two integers
int multiply(int a, int b) {
    return a * b;
}

// A function that takes a function pointer as a parameter
void printResult(int x, int y, int (*operation)(int, int)) {
    cout << "Result: " << operation(x, y) << endl;
}

int main() {
    cout << "Pointers to Functions Example" << endl;
    cout << "----------------------------" << endl;

    // Declare a function pointer and assign it to 'add'
    int (*funcPtr)(int, int) = add;
    cout << "Using function pointer to add: " << funcPtr(3, 4) << endl;

    // Reassign the function pointer to 'multiply'
    funcPtr = multiply;
    cout << "Using function pointer to multiply: " << funcPtr(3, 4) << endl;

    // Pass function pointers as arguments
    printResult(5, 6, add);
    printResult(5, 6, multiply);

    return 0;
}