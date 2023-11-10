#include<iostream>
using namespace std;

// Heapify Algorithm for max heap
void heapifyMax(int arr[], int size, int i){
    int max = i;
    int leftIndex = (2*i);
    int rightIndex = (2*i)+1;

    if(leftIndex <= size && arr[max] < arr[leftIndex]){
        max = leftIndex;
    }
    if(rightIndex <= size && arr[max] < arr[rightIndex]){
        max = rightIndex;
    }

    if(max != i){
        swap(arr[i],arr[max]);
        heapifyMax(arr, size, max);    // Neche ke saare members ko bhi toh check krna pdega!
    } else {
        return;
    }
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;

    // Creating heap
    for(int i= size/2; i > 0; i--){
        heapifyMax(arr, size, i);
    }
    
    cout<<"Printing the array after max heapifying"<< endl;
    for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}