// binary_tree.cpp
// This file demonstrates a basic binary tree implementation using pointers in C++.
// The tree supports insertion and in-order traversal.

#include <iostream>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// BinaryTree class
class BinaryTree {
private:
    Node* root;

    // Helper function for in-order traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    // Insert a value into the binary tree (not necessarily a BST)
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        // Simple insertion: fill left child first, then right (not balanced)
        Node* current = root;
        while (true) {
            if (current->left == nullptr) {
                current->left = new Node(value);
                break;
            } else if (current->right == nullptr) {
                current->right = new Node(value);
                break;
            } else {
                // Move to left subtree for simplicity
                current = current->left;
            }
        }
    }

    // In-order traversal of the tree
    void printInOrder() {
        cout << "In-order traversal: ";
        inOrder(root);
        cout << endl;
    }

    // Destructor to free memory
    ~BinaryTree() {
        // Use post-order traversal to delete nodes
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
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    tree.printInOrder();

    return 0;
}