// binary_search_tree.cpp
// This file demonstrates a binary search tree (BST) implementation using pointers in C++.
// The BST supports insertion, search, and in-order traversal.

#include <iostream>

using namespace std;

// Node structure for the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class
class BinarySearchTree {
private:
    Node* root;

    // Helper function for in-order traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Helper function for searching a value
    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        Node** current = &root;
        while (*current != nullptr) {
            if (value < (*current)->data)
                current = &((*current)->left);
            else
                current = &((*current)->right);
        }
        *current = new Node(value);
    }

    // In-order traversal of the BST
    void printInOrder() {
        cout << "In-order traversal: ";
        inOrder(root);
        cout << endl;
    }

    // Search for a value in the BST
    bool contains(int value) {
        return search(root, value);
    }

    // Destructor to free memory
    ~BinarySearchTree() {
        destroyTree(root);
    }

    void destroyTree(Node* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);

    bst.printInOrder();

    int searchValue = 6;
    cout << "Searching for " << searchValue << ": ";
    cout << (bst.contains(searchValue) ? "Found" : "Not found") << endl;

    return 0;
}