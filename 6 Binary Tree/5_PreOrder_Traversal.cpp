#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    // Implementing the constructor 
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build tree
Node *buildTree(Node *root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {   // Assuming data -1 as NULL 
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

// PreOrder Traversal
void preOrder(Node *root){
    if(root == NULL) {
        return;
    }

    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Node *root = NULL;

    // Creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // PreOrder Traversal
    preOrder(root);

    return 0;
}