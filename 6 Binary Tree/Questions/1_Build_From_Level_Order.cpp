// CREATE TREE FROM LEVEL ORDER TRAVERSAL 

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
        this-> right = NULL;
    }
};

// Function to build tree from level order traversal 
void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;

        // We consider -1 as NULL 
        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;

    q.push(root);   // Didn't used root->data bcoz we're using Node* not Node
    q.push(NULL);   // Adding a Separator 

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

int main() {
    Node *root = NULL;

    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    levelOrderTraversal(root);
}