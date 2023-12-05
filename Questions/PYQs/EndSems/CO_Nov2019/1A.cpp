#include <iostream>
using namespace std;

void restoreSorted(int A[], int size) {
    // Find the positions where the array is not in sorted order
    int firstMismatch = -1, secondMismatch = -1;
    for (int i = 0; i < size - 1; i++) {
        if (A[i] > A[i + 1]) {
            if (firstMismatch == -1) {
                firstMismatch = i;
            }
            secondMismatch = i + 1;     // Gets overwritten in case of non-adjacent swapping
        }
    }

    // Swap the elements, regardless of adjacency
    if (firstMismatch != -1 && secondMismatch != -1) {
        swap(A[firstMismatch], A[secondMismatch]);
    } else {
        cout << "No mismatched elements" << endl;
    }
}

int main() {
    int A[] = {1, 3, 2, 4, 5};
    const int size = sizeof(A)/sizeof(A[0]);

    cout << "Array after swap: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    restoreSorted(A, size);

    cout << "Original Array after swap: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
