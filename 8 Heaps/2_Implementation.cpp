#include<iostream>
using namespace std;

class Heap {
public:
int arr[100];
int size;

Heap(){
    arr[0]=-1;
    size=0;
}

// Insertion in max heap 
void insert(int val){
    size=size+1;    // 1-based indexing 
    int index=size;
    arr[index]=val;

    while(index>1){
        int parent=index/2;

        if(arr[parent]<arr[index]){     // Assuming max heap
            swap(arr[parent], arr[index]);
            index=parent;
        } else {
            return;
        }
    }
}

// Deletion in max heap
void deleteFromHeap(){
    if(size == 0){
        cout<<"Nothing to delete"<< endl;
        return;
    }

    arr[1] = arr[size];     // Put last element to first (arr is of size+1)
    size--;     // Remove last element 

    // Take root node to it's correct position 
    int i = 1;
    while(i < size){
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;
        int maxIndex = i;

        if(leftIndex < size && arr[maxIndex] < arr[leftIndex]) {
            maxIndex = leftIndex;
        }
        if(rightIndex < size && arr[maxIndex] < arr[rightIndex]) {
            maxIndex = rightIndex;
        } 
        if (i != maxIndex){
            swap(arr[i], arr[maxIndex]);
            i = maxIndex;
        } else {
            return;
        }
    }
}

// Display function in heap 
void print(){
    for(int i=1; i<=size; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}
};

int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    
    h.deleteFromHeap();
    h.print();
    return 0;
}