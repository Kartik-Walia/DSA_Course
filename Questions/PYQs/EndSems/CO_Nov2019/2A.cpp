#include <iostream>

using namespace std;

// Definition of a tree node class with an integer key
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

    // Function to get the left child of a node, returns nullptr if the node has no left child
    Node* getLeft() {
        if (this) {
            return left;
        } else {
            return nullptr;
        }
    }

    // Function to get the right child of a node, returns nullptr if the node has no right child
    Node* getRight() {
        if (this) {
            return right;
        } else {
            return nullptr;
        }
    }
};

// Function to find the parent of a node in a binary tree
Node* getParent(Node* root, Node* node) {
    if (root == nullptr || root == node) {
        return nullptr;
    }

    if (root->getLeft() == node || root->getRight() == node) {
        return root;
    }

    Node* leftSearch = getParent(root->getLeft(), node);
    if (leftSearch != nullptr) {
        return leftSearch;
    }

    return getParent(root->getRight(), node);
}

// Function to find the successor of a node in a binary search tree
int successor(Node* root, Node* x) {
    if (x->getRight()) {
        // If the node has a right child, find the leftmost node in the right subtree
        Node* successorNode = x->getRight();
        while (successorNode->getLeft()) {
            successorNode = successorNode->getLeft();
        }
        return successorNode->data;
    } else {
        // If the node doesn't have a right child, move up the tree to find the ancestor whose left child is also an ancestor of x
        Node* current = x;
        while (getParent(root, current) && getParent(root, current)->getRight() == current) {
            current = getParent(root, current);
        }

        if (getParent(root, current)) {
            return getParent(root, current)->data;
        } else {
            return -1; // -1 can be used to represent null
        }
    }
}

int main() {
    // Example usage
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    // Find the successor of the node with key 15
    int result = successor(root, root->left->right);

    // Print the result
    if (result != -1) {
        cout << "Successor of 15 is: " << result << endl;
    } else {
        cout << "No successor found for 15" << endl;
    }

    // Clean up the memory (not shown for brevity)
    return 0;
}