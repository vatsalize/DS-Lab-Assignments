#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

class SparseMatrix {
    Element *data;
    int rows, cols, nonZero;
public:
    SparseMatrix(int r, int c, int nz) {
        rows = r; cols = c; nonZero = nz;
        data = new Element[nz + 1];
        data[0] = {rows, cols, nz};
    }

    void read() {
        cout << "Enter " << nonZero << " elements (row col value):\n";
        for (int i = 1; i <= nonZero; i++)
            cin >> data[i].row >> data[i].col >> data[i].val;
    }

    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i <= nonZero; i++)
            cout << data[i].row << " " << data[i].col << " " << data[i].val << endl;
    }

    SparseMatrix add(SparseMatrix &s2) {
        if (rows != s2.rows || cols != s2.cols) {
            cout << "Addition not possible!\n";
            return SparseMatrix(0, 0, 0);
        }

        Element *result = new Element[nonZero + s2.nonZero + 1];
        int i = 1, j = 1, k = 1;

        while (i <= nonZero && j <= s2.nonZero) {
            if (data[i].row < s2.data[j].row ||
                (data[i].row == s2.data[j].row && data[i].col < s2.data[j].col)) {
                result[k++] = data[i++];
            } else if (s2.data[j].row < data[i].row ||
                (s2.data[j].row == data[i].row && s2.data[j].col < data[i].col)) {
                result[k++] = s2.data[j++];
            } else {
                int sum = data[i].val + s2.data[j].val;
                if (sum != 0) result[k++] = {data[i].row, data[i].col, sum};
                i++; j++;
            }
        }
        while (i <= nonZero) result[k++] = data[i++];
        while (j <= s2.nonZero) result[k++] = s2.data[j++];

        SparseMatrix res(rows, cols, k - 1);
        for (int x = 1; x < k; x++) res.data[x] = result[x];
        delete[] result;
        return res;
    }
};

int main() {
    int r, c, nz1, nz2;
    cout << "Enter rows, cols, and non-zero elements for Matrix 1: ";
    cin >> r >> c >> nz1;
    SparseMatrix s1(r, c, nz1);
    s1.read();

    cout << "Enter non-zero elements for Matrix 2: ";
    cin >> nz2;
    SparseMatrix s2(r, c, nz2);
    s2.read();

    cout << "\nMatrix 1:\n"; s1.display();
    cout << "\nMatrix 2:\n"; s2.display();

    SparseMatrix sum = s1.add(s2);
    cout << "\nResultant Matrix (Triplet Form):\n"; sum.display();
}
