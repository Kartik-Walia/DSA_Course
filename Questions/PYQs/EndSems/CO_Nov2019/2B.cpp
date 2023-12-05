#include <iostream>
using namespace std;

void partitionEvenOdd(int A[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        // Move left pointer to the right until an odd number is found
        while (A[left] % 2 == 0 && left < right) {
            left++;
        }
        // Move right pointer to the left until an even number is found
        while (A[right] % 2 != 0 && left < right) {
            right--;
        }
        // Swap the even and odd elements
        swap(A[left], A[right]);
    }
}

int main() {
    int A[] = {2, 7, 5, 10, 8, 3, 6};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    partitionEvenOdd(A, n);

    cout << "Partitioned Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
