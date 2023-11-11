#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node {
public:
int data;
Node *left;
Node * right;

Node(int d):data(d), left(NULL), right(NULL) {}
};

Node *buildTree(Node *root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){     // Assuming -1 as NULL
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void reverseLevelOrderTraversal(Node *root){
    if(!root){
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);
    q.push(NULL);   // Adding a Separator (bcoz in case of root there's only 1 node in that level)

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        s.push(temp);   // Irresptive of temp is NULL or not, it should be there in stack 

        if(temp == NULL){   // Means previous level is completely traversed
            if(!q.empty()){     // Queue still has some child nodes
                q.push(NULL);
            }
        } else {
            if(temp->left){ // If temp left is NOT NULL
                q.push(temp->left);
            }
            if(temp->right){ // If temp right is NOT NULL
                q.push(temp->right);
            }
        }
    }

    while(!s.empty()){
        Node *temp = s.top();
        s.pop();

        if(temp == NULL){
            cout << endl;
        } else {
        cout << temp->data << " ";
        }
    }
    cout << endl;
}

int main(){
    Node *root = NULL;

    // Creating a tree 
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Reverse Level Order Traversal
    cout << "Printing the Reverse Level Order Traversal Output" << endl;
    reverseLevelOrderTraversal(root);

    return 0;
}