// This method involves merging the two heaps in - place without using additional memory.
// It has a time complexity of O(n1 *log(n1 + n2)), making it more efficient.

/*
METHOD 2 : BETTER APPROACH

*/

#include<iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i){
    // Following 0-based indexing 
    int max = i;
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

void mergeHeapInPlace(int A[], int n1, int B[], int n2){    // n1 initial index to enter data & n2 is size 
    for(int i=0; i < n2; i++){
        A[n1 + i] = B[i];
    }

    for(int i = ((n1 + n2)/2)-1; i >= 0; i--){
        maxHeapify(A, (n1 + n2), i);
    }
}

int main(){
    int A[] = {10, 8, 5, 4, 3};
    int n1 = sizeof(A)/sizeof(A[0]);
    
    int B[] = {15, 12, 9, 7, 2};
    int n2 = sizeof(B)/sizeof(B[0]);
    
    int C[n1 + n2];

    mergeHeapInPlace(C, 0, A, n1);
    mergeHeapInPlace(C, n1, B, n2);

    cout << "Merged max heap" << endl;
    for(int i=0; i < (n1 + n2); i++){
        cout << C[i] << " ";
    }
    cout << endl;


    return 0;
}