// To see completion of a particular level we need to use a separator for it 
// Like we know after adding root a level is completed bcoz root is always gonna be a single element, so i am 
// gonna use NULL as separator for it 


#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    // Implement the constructor 
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

    if (data == -1) { // Assuming data = -1 as NULL
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
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

int main()
{
    Node *root = NULL;

    // Creating a tree
    root = buildTree(root); 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    // Level Order Traversal
    cout << "Printing the Level Order Traversal Output" << endl; 
    levelOrderTraversal(root);

    return 0;
}