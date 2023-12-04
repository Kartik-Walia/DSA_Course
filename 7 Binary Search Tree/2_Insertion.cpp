#include<iostream>
#include<queue>
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

void inOrder(Node *root){
    // Base case 
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
} 

void preOrder(Node *root){
    if(root == NULL) {
        return;
    }

    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);   // Didn't used root->data bcoz we're using Node* not Node
    q.push(NULL);   // Adding a Separator (bcoz in case of root there's only 1 node in that level)

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL) {  // Means previous level is completely traversed
            cout << endl;   // Hitting enter after completion of previous level

            if(!q.empty()) {    // Queue still has some child nodes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) { // If temp left is NOT NULL
                q.push(temp->left);
            }
            if (temp->right) { // If temp right is NOT NULL
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* &root, int d) {
    // Base case 
    if(root == NULL) {          // No Tree existed, so made a new tree with root node
        root = new Node(d);
        return root;
    }

    if(d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing level order traversal of BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Printing in order traversal of BST" << endl;
    inOrder(root);
    cout << endl;

    cout << "Printing pre order traversal of BST" << endl;
    preOrder(root);
    cout << endl;

    cout << "Printing post order traversal of BST" << endl;
    postOrder(root);
    cout << endl;

    return 0;
}

/*

Tree :
            10
          /    \
         8      21
        /        \
       7          27
      /
     5 
    /
   4 
  /
 3 

Input : 
10 8 21 7 27 5 4 3 -1

Output :
Printing level order traversal of BST
10
8 21
7 27
5
4
3

Printing in order traversal of BST
3 4 5 7 8 10 21 27
Printing pre order traversal of BST
10 8 7 5 4 3 21 27
Printing post order traversal of BST
3 4 5 7 8 27 21 10

*/