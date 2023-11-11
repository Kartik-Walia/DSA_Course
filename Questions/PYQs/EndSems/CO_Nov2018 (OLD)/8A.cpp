#include<iostream>
using namespace std;

class Node {
public:
int data;
Node *left;
Node *right;

Node(int d) : data(d), left(NULL), right(NULL) {}
};

Node *buildTree(Node *root) {
    cout << "Enter data " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){     // Assuming -1 as NULL
        return NULL;
    } 

    cout << "Enter data for entering in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for entering in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void preOrder(Node *root, int &count) {
    if(root == NULL){
        return;
    }

    if((root->left == NULL) && (root->right == NULL)){
        count++;
    }
    preOrder(root->left, count);
    preOrder(root->right, count);
}

int count_LEAF(Node *root){
    int count = 0;

    preOrder(root, count);

    return count;
}

int main(){
    Node *root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "No. of leaf nodes are " << count_LEAF(root) << endl;
    
    return 0;
}