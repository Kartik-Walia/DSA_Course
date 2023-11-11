#include<iostream>
using namespace std;

class Node {
public:
int data;
Node *left;
Node *right;

Node(int d):data(d), left(NULL), right(NULL) {}
};

Node *buildTree(Node *root){
    cout << "Enter data " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {   // Assuming -1 as NULL
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

bool isMaxOrder(Node *root) {
    // Leaf node (Base Case)
    if(root->left == NULL && root->right == NULL) {
        return true;
    }

    // Only left child exist
    if (root->right == NULL) {
        return (root->data > root->left->data);
    } else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
    }
}

int main(){
    Node *root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 6 5 3 -1 -1 2 -1 -1 4 1 -1 -1 -1

    // 6 5 3 -1 -1 2 -1 -1 4 1 -1 -1 8 -1 -1
    
    cout << (isMaxOrder(root) ? "Yes, it satisfies max heap property" : "No, it doesn't satisfies max heap property") << endl;

    return 0;
}