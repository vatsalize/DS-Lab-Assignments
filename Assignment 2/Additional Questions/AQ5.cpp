#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int countTwos = 0;

    // Count number of 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) countTwos++;
    }

    // Work backwards
    int i = n - 1;
    int j = n + countTwos - 1; // virtual expanded array index

    while (i >= 0 && j >= 0) {
        if (arr[i] == 2) {
            if (j < n) arr[j] = 2;
            j--;
            if (j < n) arr[j] = 2;
            j--;
        } else {
            if (j < n) arr[j] = arr[i];
            j--;
        }
        i--;
    }
}

int main() {
    int arr[] = {1,2,3,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicateTwos(arr, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
