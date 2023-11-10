#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class circularQueue{
    Node *rear;

public:
    circularQueue() : rear(NULL) {}

    void enqueue(int val){
        Node *newNode = new Node(val);

        if (isEmpty()){ // Entering first element
            rear = newNode;
            rear->next = rear; // Point back to itself
        }else{
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue(){
        if (isEmpty()){
            cout << "Queue Underflow!" << endl;
            return -1;
        }

        int removedVal = rear->next->data; // Gets data of front node
        if (rear->next == rear){ // Single element present
            delete rear;
            rear = NULL;
        }else{
            Node *temp = rear->next; // temp points to first node
            rear->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        return removedVal;
    }

    bool isEmpty(){
        if (rear == NULL){
            return true;
        }else{
            return false;
        }
    }

    void display(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *current = rear->next;
        do{
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);
        cout << endl;
    }
};

int main(){
    circularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.dequeue();
    cq.display();

    cq.enqueue(30);
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cout << "Is the circular queue empty? " << (cq.isEmpty() ? "Yes" : "No") << endl;

    cq.dequeue();

    return 0;
}