#include <iostream>
using namespace std;

// Updated definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;  // Added parent pointer
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* minVal(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* successor(TreeNode* x) {
    if (x->right != NULL) {
        // If the node has a right child, find the leftmost node in the right subtree
        return minVal(x->right);
    } else {
        // If the node does not have a right child, go up the tree to find the first ancestor
        // whose left child is also an ancestor of the given node.
        TreeNode* parent = x->parent;
        while (parent != NULL && x == parent->right) {
            x = parent;
            parent = x->parent;
        }
        return parent;
    }
}

// Sample usage
int main() {
    // Create a sample Binary Search Tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Set parent pointers
    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->right->left->parent = root->right;
    root->right->right->parent = root->right;

    // Example: Find the successor of the node with value 4
    TreeNode* nodeToFindSuccessor = root->left->right;
    TreeNode* successorNode = successor(nodeToFindSuccessor);

    if (successorNode != NULL) {
        cout << "Successor of " << nodeToFindSuccessor->val << " is: " << successorNode->val << endl;
    } else {
        cout << "No successor found." << endl;
    }

    return 0;
}
