// In case of Circular queue, front & rear starts from -1 instead of 0
// When rear reaches end at time of enqueue, make rear to start to maintain cyclic nature 
// When front reaches end at time of enqueue, make front to start to maintain cyclic nature 

// REMEMBER :
// -> Full/Empty 
// -> First/Single Element 
// -> Maintain Cyclic Nature 
// -> Normal Flow 

#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int front, rear, size;

    public:
    // Implement the constructor 
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }


    // <------------------------------- PUBLIC FUNCTIONS OF CIRCULAR QUEUE ------------------------------->
    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int val) {
        // To check whether queue is full 
        if ((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))) {
            return false;
        }
         
        if (front == -1) {   // First element to push
            front = rear = 0;
            arr[rear] = val;
        } else if (front != 0 && rear == size-1){
            rear = 0;   // To maintain cyclic nature
            arr[rear] = val;
        } else {    // Normal flow
            rear++;
            arr[rear] = val;
        }

        return true;
    }


    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // To check whether queue if empty
        if(front == -1){
            return -1;
        } 
        
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) {    // Single element present
            front = rear = -1;
        } else if (front == size-1) {
            front = 0;  // To maintain cyclic nature
        } else {    // Normal flow
            front++;
        }

        return ans;
    }


    bool isEmpty(){
        if(front == -1){
            return true;
        } else {
            return false;
        }
    }
};


int main(){
    CircularQueue q(100);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);


    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;


    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeue: " << q.dequeue() << endl;

    return 0;
}