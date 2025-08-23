#include <iostream>
using namespace std;

class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i - j == 0) A[n - 1 + i - 1] = x;       // main diagonal
        else if (i - j == 1) A[i - 1] = x;          // lower diagonal
        else if (j - i == 1) A[2*n - 1 + i - 1] = x; // upper diagonal
    }
    int get(int i, int j) {
        if (i - j == 0) return A[n - 1 + i - 1];
        else if (i - j == 1) return A[i - 1];
        else if (j - i == 1) return A[2*n - 1 + i - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    TriDiagonal td(5);
    td.set(1,1,1); td.set(1,2,2);
    td.set(2,1,3); td.set(2,2,4); td.set(2,3,5);
    td.set(3,2,6); td.set(3,3,7); td.set(3,4,8);
    td.set(4,3,9); td.set(4,4,10); td.set(4,5,11);
    td.set(5,4,12); td.set(5,5,13);
    td.display();
}
