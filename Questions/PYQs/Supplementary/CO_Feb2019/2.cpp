#include<iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i){
    int max = i;
    int leftIndex = (2*i) + 1;
    int rightIndex = (2*i) + 2;

    if(leftIndex < size && arr[leftIndex] > arr[max]){
        max = leftIndex;
    }
    if(rightIndex < size && arr[rightIndex] > arr[max]){
        max = rightIndex;
    }

    if(max != i){
        swap(arr[i], arr[max]);
        maxHeapify(arr, size, max); // For all memebers below that node 
    }
}

int main(){
    int arr[] = {62, 31, 70, 91, 25, 11, 9, 61, 73, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=(size/2)-1; i >= 0; i--) {
        maxHeapify(arr, size, i);
        cout << "running heapify for "<< i<< "th index" << endl;
        // Print array after each heapify operation
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Printing array after max heapifying " << endl;
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*

              62
        /           \
       31           70
   /      \        /   \
  91      25      11    9
 /  \    /
61  73  6

{62 31 70 91 25 11 9 61 73 6}


FOR 25 (i=4)
              62
        /           \
       31           70
   /      \        /   \
  91      25      11    9
 /  \    /
61  73  6

{62 31 70 91 25 11 9 61 73 6}


FOR 91 (i=3)
              62
        /           \
       31           70
   /      \        /   \
  91      25      11    9
 /  \    /
61  73  6

{62 31 70 91 25 11 9 61 73 6}


FOR 70 (i=2)
              62
        /           \
       31           70
   /      \        /   \
  91      25      11    9
 /  \    /
61  73  6

{62 31 70 91 25 11 9 61 73 6}


FOR 31 (i=1)
              62
        /           \
       91           70
   /      \        /   \
  73      25      11    9
 /  \    /
61  31  6

{62 91 70 73 25 11 9 61 31 6}


FOR 62 (i=0)
              91
        /           \
       73           70
   /      \        /   \
  62      25      11    9
 /  \    /
61  31  6

{91 73 70 62 25 11 9 61 31 6}


*/