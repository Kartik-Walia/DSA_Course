#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DEqueue{
    Node *front;
    Node *rear;

public:
    DEqueue() : front(NULL), rear(NULL) {}

    void pushFront(int val){
        Node *newNode = new Node(val);

        if (isEmpty()){ // Entering first element
            front = rear = newNode;
        }else{
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void pushRear(int val){
        Node *newNode = new Node(val);

        if (isEmpty()){ // Entering first element
            front = rear = newNode;
        }else{
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int popFront(){
        if (isEmpty()){
            cout << "Queue underflow!" << endl;
            return -1;
        }

        int removedVal = front->data;
        Node *temp = front;
        if (front == rear){ // Single element
            front = rear = NULL;
            delete temp;
        }else{
            front = front->next;
            front->prev = NULL;
            temp->next = NULL;
            delete temp;
        }

        return removedVal;
    }

    int popRear(){
        if (isEmpty()){
            cout << "Queue underflow!" << endl;
            return -1;
        }

        int removedVal = rear->data;
        Node *temp = rear;
        if (front == rear){
            front = rear = NULL;
            delete temp;
        }else{
            rear = rear->prev;
            rear->next = NULL;
            temp->prev = NULL;
            delete temp;
        }

        return removedVal;
    }

    bool isEmpty(){
        if (front == NULL){
            return true;
        }else{
            return false;
        }
    }

    void display(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
        }

        Node *current = front;
        while (current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    DEqueue dq;

    dq.pushFront(10);
    dq.pushFront(20);
    dq.pushRear(30);
    dq.display();

    dq.popFront();
    dq.popRear();
    dq.display();

    return 0;
}