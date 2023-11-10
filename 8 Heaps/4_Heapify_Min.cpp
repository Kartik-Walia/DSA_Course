#include<iostream>
using namespace std;

// Heapify Algorithm for min heap
void heapifyMin(int arr[], int size, int i){
    int min = i;
    int leftIndex = (2*i);
    int rightIndex = (2*i)+1;

    if(leftIndex <= size && arr[min] > arr[leftIndex]){
        min = leftIndex;
    }
    if(rightIndex <= size && arr[min] > arr[rightIndex]){
        min = rightIndex;
    }
    if(min != i){
        swap(arr[i],arr[min]);
        heapifyMin(arr, size, min);    // Neche ke saare members ko bhi toh check krna pdega!
    } else {
        return;
    }
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;

    // Creating heap
    for(int i= size/2; i > 0; i--){
        heapifyMin(arr, size, i);
    }
    
    cout<<"Printing the array after min heapifying"<< endl;
    for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}