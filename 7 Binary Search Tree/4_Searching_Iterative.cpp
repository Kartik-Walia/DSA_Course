#include<iostream>
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

bool searchTree(Node *root, int key) {
    Node *temp = root;

    while (temp!= NULL) {
        if (key == temp->data) {
            return true;
        } else if (key < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return false;
}

int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << "Binary Search Tree created." << endl;

    int key;
    cout << "Enter a value to search in the tree: ";
    cin >> key;

    if (searchTree(root, key)) {
        cout << key << " found in the tree." << endl;
    } else {
        cout << key << " not found in the tree." << endl;
    }

    return 0;
}
