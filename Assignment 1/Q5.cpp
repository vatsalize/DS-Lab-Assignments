#include <iostream>
using namespace std;

void sumRowsAndColumns(int m, int n, int arr[][100]) {
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
        }
        cout << "sum of row " << i + 1 << " = " << rowSum << endl;
    }

    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += arr[i][j];
        }
        cout << "sum of column " << j + 1 << " = " << colSum << endl;
    }
}

int main() {
    int m, n;
    cout << "enter number of rows and columns: ";
    cin >> m >> n;

    int arr[100][100];
    cout << "enter elements of the array:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    sumRowsAndColumns(m, n, arr);

    return 0;
}