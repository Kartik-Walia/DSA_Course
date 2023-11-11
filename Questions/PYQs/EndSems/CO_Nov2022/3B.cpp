/*

Algorithm :
1. Create an empty queue q.
2. Enqueue the root node into q.
3. Enqueue a NULL separator to mark the end of the first level.
4. Run a loop until the queue is not empty:
    a. Dequeue a node temp from q.
    b. If temp is NULL, it means the previous level is completely traversed. 
        Print a newline and enqueue a NULL if there are more levels.
    c. If temp is not NULL, print the data of temp.
        Enqueue the left child of temp if it exists.
        Enqueue the right child of temp if it exists.

*/

#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
int data;
Node *left;
Node *right;

Node(int d):data(d), left(NULL), right(NULL) {}
};

Node *buildTree(Node *root) {
    cout << "Enter data" << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1) {    // Assuming -1 as NULL
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);   // First level consists only of 1 node 

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;

            if(!q.empty()){     // Child nodes are present 
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node *root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "Printing level order traversal " << endl;
    levelOrderTraversal(root);
    
    return 0;
}