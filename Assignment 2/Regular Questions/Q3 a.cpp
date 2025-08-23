#include <iostream>
using namespace std;

int linear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;   
        }
    }
    return n;   
}

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;

    int arr[n - 1];
    cout << "enter " << n - 1 << " elements in sorted order: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "missing number: " << linear(arr, n);
    return 0;
}