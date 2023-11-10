// In case of Doubly Ended queue, front & rear starts from -1 instead of 0

// Phle change kiya fir dala 

// REMEMBER :
// -> Full/Empty
// -> First/Single Element
// -> Maintain Cyclic Nature
// -> Normal Flow

#include <iostream>
using namespace std;

class DEqueue{
    int *arr;
    int front, rear, size;

public:
    // Implement the constructor
    DEqueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // <------------------------------- PUBLIC FUNCTIONS OF DOUBLY ENDED QUEUE ------------------------------->

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty(){
        if(front == -1){
            return true;
        } else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull(){
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))) {
            return true;
        } else{
            return false;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront(){
        if (isEmpty()){
            cout<<"DE_Queue is empty!"<<endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear(){
        if (isEmpty()){
            cout<<"DE_Queue is empty!"<<endl;
            return -1;
        } else {
            return arr[rear];
        }
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x){
        if (isFull()){
            cout<<"Queue Overflow!"<<endl;
            return false;
        } else if (isEmpty()) {   // First element to push
            front = rear = 0;
            arr[front] = x;
        } else if (front == 0) {    // Maintaining cyclic nature
            front = size-1;
            arr[front] = x;
        } else {    // Normal flow
            front--;
            arr[front] = x;
        }
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    // Similar to Circular Queue's Enqueue
    bool pushRear(int x){
        if (isFull()){
            cout << "Queue Overflow!" << endl;
            return false;
        } else if (isEmpty()) {   // First element to push
            front = rear = 0;
            arr[rear] = x;
        } else if (front != 0 && rear == size-1) {    // Maintaining cyclic nature
            rear = 0;
            arr[rear] = x;
        } else {    // Normal flow
            rear++;
            arr[rear] = x;
        }
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    // Similar to Circular Queue's Dequeue 
    int popFront(){
        if(isEmpty()){
            cout<<"Queue underflow!"<<endl;
            return -1;
        } 

        int removedVal = arr[front];
        arr[front] = -1;
        if (front == rear) {     // Single element
            front = rear = -1;
        } else if (front == size-1) {    // Maintaining cyclic nature
            front = 0;
        } else {    // Normal flow
            front++;
        }

        return removedVal;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear(){
        if(isEmpty()){
            cout << "Queue underflow!" << endl;
            return -1;
        } 

        int removedVal = arr[rear];
        arr[rear] = -1;
        if (front == rear) {     // Single element
            front = rear = -1;
        } else if (rear == 0) {    // Maintaining cyclic nature
            rear = size-1;
        } else {    // Normal flow
            rear--;
        }

        return removedVal;
    }
};


int main()
{
    DEqueue d(100);

    d.pushFront(12);
    d.pushRear(14);

    cout << d.getFront() << endl;
    cout << d.getRear() << endl;

    d.popFront();

    cout << d.getFront() << endl;
    cout << d.getRear() << endl;

    d.popRear();

    if (d.isEmpty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty " << endl;
    }

    return 0;
}