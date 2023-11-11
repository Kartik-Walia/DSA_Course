#include<iostream>
using namespace std;

class Node {
public:
int data;
Node *left;
Node *right;

Node(int d): data(d), left(NULL), right(NULL) {}
};

Node *buildTree(Node *root){
    cout << "Enter the data " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int countNodes(Node *root) {
    if(root == NULL) {  // Base case
        return 0;
    }

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node *root, int index, int count) {
    if(root == NULL) {
        return true;
    }

    if (index >= count) {
        return false;
    } else {
        bool left = isCBT(root->left, (2*index) + 1, count);
        bool right = isCBT(root->right, (2*index) + 2, count);

        return (left && right);
    }
}

bool isMaxOrder(Node *root) {
    // Leaf Node (Base Case)
    if (root->left == NULL && root->right == NULL) {
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

bool isHeap(Node *root) {
    int index = 0;
    int totalCount = countNodes(root); 
    if (isCBT(root, index, totalCount) && isMaxOrder(root)) {
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

    cout << (isHeap(root) ? "Yes, it's a max heap" : "No, it's not a max heap") << endl;
    
    return 0;
}

/*

Time Complexity = O(n) + O(n) + O(n) = O(n)

*/