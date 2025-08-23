#include <iostream>
using namespace std;

class Diagonal {
    int *A;
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i - 1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i - 1];
        return 0;
    }
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};
int main() {
    Diagonal d(5);
    d.set(1,1,10); d.set(2,2,20); d.set(3,3,30); d.set(4,4,40); d.set(5,5,50);
    d.display();
}
