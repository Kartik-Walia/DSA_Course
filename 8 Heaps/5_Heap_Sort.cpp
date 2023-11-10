#include<iostream>
using namespace std;

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
        swap(arr[i], arr[max]);
        heapifyMax(arr, size, max);     // To check memeber below 
    } else {
        return;
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]);   // Swap root node with last node 
        size--; // Consider remaining heap (remove last element)

        heapifyMax(arr, size, 1);   // Take root node to it's correct position
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

    heapSort(arr, size);
    
    cout<<"Printing the array after heap sort"<< endl;
    for(int i=1; i<=size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}