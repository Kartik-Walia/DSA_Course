#include <iostream>
using namespace std;

void merge3Sorted(const vector<int> &A, const vector<int> &B, const vector<int> &C, vector<int> &result) {
    int i = 0, j = 0, k = 0;
    while (i < A.size() || j < B.size() || k < C.size()) {
        int minVal = min(min((i < A.size() ? A[i] : INT_MAX), (j < B.size() ? B[j] : INT_MAX)), (k < C.size() ? C[k] : INT_MAX));
        result.push_back(minVal);

        if (i < A.size() && A[i] == minVal) {
            i++;
        } else if (j < B.size() && B[j] == minVal) {
            j++;
        } else if (k < C.size() && C[k] == minVal) {
            k++;
        }
    }
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(4);

    vector<int> B;
    B.push_back(2);
    B.push_back(5);

    vector<int> C;
    C.push_back(3);
    C.push_back(6);

    vector<int> result;
    merge3Sorted(A, B, C, result);

    cout << "Merged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
