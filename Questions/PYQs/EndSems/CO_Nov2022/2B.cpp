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

bool preOrder(Node *root) {
    if (root == NULL) { // Base case
        return true;
    }
    
    if ((root->left && root->left->data > root->data) || (root->right && root->right->data > root->data)) {
        return false;
    }    

    if(!preOrder(root->left)) {
        return false;
    }
    
    if(!preOrder(root->right)) {
        return false;
    }


    return true;
}

bool isMaxHeap(Node *root) {
    if(preOrder(root)) {
        return true; 
    } else {
        return false;
    }
}

int main(){
    Node *root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 6 5 3 -1 -1 2 -1 -1 4 1 -1 -1 -1

    // 6 5 3 -1 -1 2 -1 -1 4 1 -1 -1 8 -1 -1
    
    cout << (isMaxHeap(root) ? "Yes, it satisfies max heap property" : "No, it doesn't satisfies max heap property") << endl;

    return 0;
}