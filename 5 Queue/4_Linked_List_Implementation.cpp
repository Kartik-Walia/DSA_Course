// QUEUE NEVER GETS FULL IN CASE OF LINKED LIST IMPLEMENTATION

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class Queue{
    Node *front;
    Node *rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    ~Queue(){
        cout << endl;
        cout << "Calling destructor" << endl;
        while (!isEmpty()){
            dequeue();
        }
    }

    bool isEmpty(){
        if (front == NULL){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int value){
        Node *newNode = new Node(value);
        if (isEmpty()){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << endl;
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue Underflow!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        cout << "Dequeued " << temp->data << endl;
        delete temp;
    }

    void display(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *current = front;
        while (current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void qfront(){
        if (isEmpty()){
            cout << "Queue is empty!" << endl;
            return;
        }else{
            cout << "Front element is " << front->data << endl;
        }
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.qfront();

    q.dequeue();
    q.dequeue();

    q.display();
    q.qfront();

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
