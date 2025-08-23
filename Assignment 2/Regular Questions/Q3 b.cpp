#include <iostream>
using namespace std;

int binary(int arr[], int n) {
    int low = 0, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return low + 1;
}

int main() {
    int n;
    cout << "enter n: ";
    cin >> n;

    int arr[n - 1];
    cout << "enter " << n - 1 << "sorted elements: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "missing number" << binary(arr, n) << endl;

    return 0;
}