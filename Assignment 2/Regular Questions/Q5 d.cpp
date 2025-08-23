#include <iostream>
using namespace std;

class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) A[(j*(j-1))/2 + (i-1)] = x;
    }
    int get(int i, int j) {
        if (i <= j) return A[(j*(j-1))/2 + (i-1)];
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
    UpperTriangular ut(4);
    ut.set(1,1,1); ut.set(1,2,2); ut.set(1,3,3); ut.set(1,4,4);
    ut.set(2,2,5); ut.set(2,3,6); ut.set(2,4,7);
    ut.set(3,3,8); ut.set(3,4,9);
    ut.set(4,4,10);
    ut.display();
}
