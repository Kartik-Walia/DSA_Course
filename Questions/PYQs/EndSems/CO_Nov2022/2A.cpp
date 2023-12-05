/*

Algorithm :
1. Define a recursive function isBST with the following parameters:
   a. Node *root: Current node being processed
   b. int min: Minimum valid value for the current node
   c. int max: Maximum valid value for the current node
2. Base Case:
   a. If root is NULL, return true (an empty tree is a BST).
3. If the current node's data is greater than min and less than max:
   a. Recursively call isBST for the left subtree with updated max value as root->data.
   b. Recursively call isBST for the right subtree with updated min value as root->data.
4. If the conditions in step 3 are not met, return false (violates the BST property).
5. In the validateBST function, call isBST with the root node and initial minimum and maximum values (INT_MIN, INT_MAX).
6. Return the result obtained from step 5.

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isBST(Node *root, int min, int max) {
    // Base case 
    if(root == NULL) {
        return true;
    }
    if(root->data > min && root->data < max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    } else {
        return false;
    }
}

bool validateBST(Node *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    // Creating a sample binary search tree
    Node* root = new Node(9);
    root->left = new Node(7);
    root->right = new Node(11);

    // Validating if the tree is a binary search tree
    if (validateBST(root)) {
        cout << "The tree is a Binary Search Tree (BST)." << endl;
    } else {
        cout << "The tree is not a Binary Search Tree (BST)." << endl;
    }

    // Clean up: Delete dynamically allocated nodes (in a real-world scenario, you might have a proper cleanup mechanism)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
