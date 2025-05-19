// avl_tree.cpp
// This file demonstrates an AVL tree implementation using pointers in C++.
// AVL trees are self-balancing binary search trees. This example supports insertion and in-order traversal.

#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for the AVL tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// AVLTree class
class AVLTree {
private:
    Node* root;

    // Get the height of a node
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    // Get the balance factor of a node
    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Right rotate subtree rooted with y
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    // Left rotate subtree rooted with x
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    // Insert a value and balance the tree
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; // No duplicates

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // In-order traversal
    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Destructor helper
    void destroyTree(Node* node) {
        if (!node) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void printInOrder() {
        cout << "In-order traversal: ";
        inOrder(root);
        cout << endl;
    }

    ~AVLTree() {
        destroyTree(root);
    }
};

int main() {
    AVLTree avl;
    avl.insert(20);
    avl.insert(4);
    avl.insert(15);
    avl.insert(70);
    avl.insert(50);

    avl.printInOrder();

    return 0;
}