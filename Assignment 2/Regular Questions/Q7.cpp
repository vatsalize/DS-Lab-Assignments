#include <iostream>
using namespace std;

int countInversions(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "enter the size of array";
    cin >> n;

    int A[100];
    cout << "enter" << n << "elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int totalInversions = countInversions(A, n);
    cout << "total number of inversions = " << totalInversions << endl;

    return 0;
}