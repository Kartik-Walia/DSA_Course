#include<iostream>
using namespace std;

class modifiedQueue {
    int *arr, *deletedCount;
    int front, rear, size;
public:
modifiedQueue(int size){
    front=rear=0;
    this->size=size;
    arr=new int[size];
    deletedCount=new int[size];
    for(int i=0; i<size; i++){
        deletedCount[i]=0;
    }
}

~modifiedQueue(){
    delete[] arr;
    delete[] deletedCount;
}

void InsertQ(int val){
    if(isFull()){
        cout<<"Queue overflow"<<endl;
        return;
    } else {
        arr[rear]=val;
        rear++;
    }
}

int DeleteQ(){
    if(isEmpty()){
        cout<<"Queue underflow!"<<endl;
        return -1;  // Assuming -1 as return for empty queue
    } else {
        int removedVal=arr[front];
        arr[front] = -1;
        front++;

        // Space utilization 
        if(isEmpty()){
            front=rear=0;
        }
        
        if(deletedCount[removedVal]==0){
            arr[rear]=removedVal;
            rear++;
            deletedCount[removedVal]+=1;
        } else {
            deletedCount[removedVal]=0;
        }

        return removedVal;
    }
}

bool isEmpty(){
    return front==rear;
}

bool isFull(){
    return rear==size;
}

void Display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    for (int i = front; i < rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

};

int main(){
    modifiedQueue myQueue(5);

    myQueue.InsertQ(1);
    myQueue.Display();

    myQueue.InsertQ(2);
    myQueue.Display();

    myQueue.InsertQ(3);
    myQueue.Display();

    myQueue.DeleteQ();
    myQueue.Display();
    
    myQueue.DeleteQ();
    myQueue.Display();
    
    myQueue.DeleteQ();
    myQueue.Display();
    
    myQueue.DeleteQ();
    myQueue.Display();
    
    myQueue.DeleteQ();
    myQueue.Display();
    
    myQueue.DeleteQ();
    myQueue.Display();

    return 0;
}