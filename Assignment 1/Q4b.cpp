#include <iostream>
using namespace std;

void multiplyMatrices(int a[2][3], int b[3][2], int c[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[2][3] = { {11, 12, 13}, {14, 15, 16} };
    int b[3][2] = { {17, 18}, {19, 20}, {21, 22} };
    int c[2][2];

    multiplyMatrices(a, b, c);

    cout << "Final Matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}