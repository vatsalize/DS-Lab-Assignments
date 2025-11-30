#include <iostream>
using namespace std;

void transposeMatrix(int m, int n, int arr[][100], int trans[][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            trans[j][i] = arr[i][j];
        }
    }
}

int main() {
    int m, n;
    cout << "enter the number of rows and columns";
    cin >> m >> n;
    int arr[100][100], trans[100][100];

    cout << "enter the elements of array" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    transposeMatrix(m, n, arr, trans);

    cout << "The transpose of matrix is\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}