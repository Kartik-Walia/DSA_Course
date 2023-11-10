/*
METHOD 1 : NAIVE APPROACH
1. Create a new array and copy elements from both heaps into the new array.
2. Afterwards, transform array into a max heap.

Time Complexity is O(n1 + n2), where n1 & n2 are sizes of 2 heaps
*/

#include<iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i){
    int max = i;
    // Following 0-based indexing 
    int leftIndex = (2*i)+1;
    int rightIndex = (2*i)+2;

    if(leftIndex < size && arr[leftIndex] > arr[max]){
        max = leftIndex;
    }
    if(rightIndex < size && arr[rightIndex] > arr[max]){
        max = rightIndex;
    }

    if(max != i){
        swap(arr[i], arr[max]);
        maxHeapify(arr, size, max);
    } else {
        return;
    }
}

void buildHeap(int arr[], int n){
    for(int i = (n/2) - 1; i >= 0; i--){
        maxHeapify(arr, n, i);
    }
}

void mergeHeaps(int A[], int n1, int B[], int n2, int C[]){
    for(int i=0; i<n1; i++){
        C[i] = A[i];
    }
    for(int i=0; i<n2; i++){
        C[n1+i] = B[i];
    }

    for(int i=0; i < (n1 + n2); i++){
        cout << C[i] << " ";
    }
    cout << endl;

    buildHeap(C, (n1 + n2));
}

int main(){
    int A[] = {10, 8, 5, 4, 3};
    int n1 = sizeof(A)/sizeof(A[0]);
    
    int B[] = {15, 12, 9, 7, 2};
    int n2 = sizeof(B)/sizeof(B[0]);

    int C[n1 + n2];

    mergeHeaps(A, n1, B, n2, C);

    cout << "Merged max heap" << endl;
    for(int i=0; i < (n1 + n2); i++){
        cout << C[i] << " ";
    }
    cout << endl;
    
    return 0;
}