#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front, rear, size;

    public:
    // Implement the constructor 
    Queue(){
        size = 10001;
        arr = new int[size];
        front = rear = 0;
    }

    // <------------------------------- PUBLIC FUNCTIONS OF QUEUE ------------------------------->
    bool isEmpty(){
        if (rear == front){
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int data){
        if (rear == size){  // Check if Queue is full
            cout << "Queue is Full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            int tmp = arr[front];
            arr[front] = -1;
            front++;

            // Space Utilization (when queue becomes empty take front & rear both to start)
            if(front == rear){
                front = rear = 0;
            }

            return tmp;
        }
    }

    int qfront(){
        if(isEmpty()){
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.qfront() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    cout << "Front element: " << q.qfront() << endl;

    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}