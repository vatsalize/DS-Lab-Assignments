#include <iostream>
#include <cstring>
using namespace std;

void sortStrings(char arr[][50], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[50];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

int main() {
    int n;
    cout << "enter number of strings: ";
    cin >> n;

    char arr[20][50];
    cout << "enter " << n << "strings";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sortStrings(arr, n);

    cout << "strings in alphabetical order";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}