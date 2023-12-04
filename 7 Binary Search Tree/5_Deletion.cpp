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

Node *minVal(Node *root) {
    Node *temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int key) {
    if(root == NULL) {
        return root;
    }

    if(root->data == key) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // Left child 
        if(root->left !=NULL && root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Right child
        if(root->left == NULL && root->right != NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child (Approach 2 : Taking out minimum value from right i.e. inorder successor)
        if(root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right)->data;   // Find min value from right i.e. inorder successor
            root->data = mini;  // copy min value to root 
            root->right = deleteFromBST(root->right, mini);     // delete min value node 
            return root;
        }

    } else if(root->data > key) {
        root->left = deleteFromBST(root->left, key);
        return root;
    } else {
        root->right = deleteFromBST(root->right, key);
        return root;
    }
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

    cout << "Deleting 50 from BST" << endl;
    root = deleteFromBST(root, 50);

    cout << "Printing level order traversal of BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Printing in order traversal of BST" << endl;
    inOrder(root);
    cout << endl;

    return 0;
}

/*

Tree considered :
        50
      /    \
     20     70
    /  \      \
   10   30    90
               \
               110

Input:
50 20 70 10 30 90 110 -1

Output:
Printing level order traversal of BST
50
20 70
10 30 90
110

Printing in order traversal of BST
10 20 30 50 70 90 110
Deleting 50 from BST
Printing level order traversal of BST
70
20 90
10 30 110

Printing in order traversal of BST
10 20 30 70 90 110

*/