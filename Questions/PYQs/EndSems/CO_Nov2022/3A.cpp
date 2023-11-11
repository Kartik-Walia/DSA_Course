/*

Pre-Order   JCBADEFIGH     {NLR}
In-Order    ABCEDFJGIH     {LNR}

Pre-Order first gives root, so root is J
 J
/ \

All elements in left of J in In-Order traversal are part of it's left binary tree & same goes for right
Elements in Binray Tree in Left of J are {ABCEDF}
Elements in Binray Tree in Right of J are {GIH}

In pre-order after J comes C, means C is Root node for left binary tree after J
  J
 / \
C
Elements in Binray Tree in Left of C are {AB}
Elements in Binray Tree in Right of C are {EDF}

In pre-order after C comes B, means B is Root node for left binary tree after C
    J
   / \
  C
 /
B
Elements in Binray Tree in Left of B are {A}
Elements in Binray Tree in Right of B are {NULL}
      J
     / \
    C
   /
  B
 / \
A  NULL

NULL means we are now back to B, then back to C
In pre-order after A comes D, means D is Root node for right binary tree after C (Left of C is already covered)
      J
     / \
    C
   / \
  B   D
 / \
A  NULL
Elements in Binray Tree in Left of D are {E}
Elements in Binray Tree in Right of D are {F}
              J
        /           \
       C
   /      \
  B        D
 / \      / \
A  NULL  E   F

Now we're back to J
In pre-order after F comes I, means I is Root node for right binary tree after J (Left of J is already covered)
              J
        /           \
       C             I
   /      \
  B        D
 / \      / \
A  NULL  E   F
Elements in Binray Tree in Left of I are {G}
Elements in Binray Tree in Right of I are {H}
              J
        /           \
       C             I
   /      \        /   \
  B        D      G     H
 / \      / \
A  NULL  E   F


FINAL BINARY TREE IS
              J
        /           \
       C             I
   /      \        /   \
  B        D      G     H
 /        / \
A        E   F


It's Post-Order traversal is ABEFDCGHIJ

*/

#include<iostream>
using namespace std;

class Node {
public:
char data;
Node *left;
Node *right;

Node(char d):data(d), left(NULL), right(NULL) {}
};

// Function to find index of a vaue in an array 
int findIndex(char inOrder[], char value, int start, int end){
      for(int i=start; i <= end; i++){
            if(inOrder[i] == value){
                  return i;
            }
      }
      return -1;  // Not found!
}

// Function to build binary tree
Node *buildTree(char preOrder[], char inOrder[], int preStart, int preEnd, int inStart, int inEnd)
{
      if(preStart > preEnd){
            return NULL;
      }

      char rootValue = preOrder[preStart];
      Node *root = new Node(rootValue);

      int inOrderIndex = findIndex(inOrder, rootValue, inStart, inEnd);
      int leftSubTreeSize = (inOrderIndex - inStart);

      root->left = buildTree(preOrder, inOrder, preStart + 1, preStart + leftSubTreeSize, inStart, inOrderIndex - 1);
      root->right = buildTree(preOrder, inOrder, preStart + leftSubTreeSize + 1, preEnd, inOrderIndex + 1, inEnd);

      return root;
}

void postOrder(Node *root){
      if(root == NULL){ // Base case
            return;
      }

      postOrder(root->left);
      postOrder(root->right);
      cout << root->data << " ";
}



int main(){
      char preOrder[] = {'J', 'C', 'B', 'A', 'D', 'E', 'F', 'I', 'G', 'H'};
      char inOrder[] = {'A', 'B', 'C', 'E', 'D', 'F', 'J', 'G', 'I', 'H'};

      // Passing end as size-1 
      Node *root = buildTree(preOrder, inOrder, 0, sizeof(preOrder)/sizeof(preOrder[0]) - 1, 0, sizeof(inOrder)/sizeof(inOrder[0]) - 1);

      cout << "Post-order Traversal of the Constructed Tree: ";
      postOrder(root);
      cout << endl;

      return 0;
}