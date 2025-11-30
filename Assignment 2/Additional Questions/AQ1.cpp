#include <iostream>
using namespace std;

int difference(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, k;
    int arr[100];

    cout << "enter size of array: ";
    cin >> n;

    cout << "enter " << n << "elements";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "enter value of k: ";
    cin >> k;

    int totalPairs = difference(arr, n, k);

    cout << "total pairs with difference " << k << " = " << totalPairs << endl;

    return 0;
}