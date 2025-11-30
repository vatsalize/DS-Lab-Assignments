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

    SparseMatrix transpose() {
        SparseMatrix result(cols, rows, nonZero);
        int k = 1;
        for (int c = 0; c < cols; c++) {
            for (int i = 1; i <= nonZero; i++) {
                if (data[i].col == c)
                    result.data[k++] = {data[i].col, data[i].row, data[i].val};
            }
        }
        return result;
    }

    SparseMatrix multiply(SparseMatrix &s2) {
        if (cols != s2.rows) {
            cout << "Multiplication not possible!\n";
            return SparseMatrix(0, 0, 0);
        }

        SparseMatrix s2T = s2.transpose();
        Element *temp = new Element[rows * s2.cols + 1];
        int k = 1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < s2.cols; j++) {
                int sum = 0;
                for (int x = 1; x <= nonZero; x++) {
                    if (data[x].row == i) {
                        for (int y = 1; y <= s2T.nonZero; y++) {
                            if (s2T.data[y].row == j && s2T.data[y].col == data[x].col)
                                sum += data[x].val * s2T.data[y].val;
                        }
                    }
                }
                if (sum != 0) temp[k++] = {i, j, sum};
            }
        }

        SparseMatrix result(rows, s2.cols, k - 1);
        for (int x = 1; x < k; x++) result.data[x] = temp[x];
        delete[] temp;
        return result;
    }
};

int main() {
    int r1, c1, nz1, r2, c2, nz2;
    cout << "Enter rows, cols, non-zero elements for Matrix 1: ";
    cin >> r1 >> c1 >> nz1;
    SparseMatrix s1(r1, c1, nz1);
    s1.read();

    cout << "Enter rows, cols, non-zero elements for Matrix 2: ";
    cin >> r2 >> c2 >> nz2;
    SparseMatrix s2(r2, c2, nz2);
    s2.read();

    cout << "\nMatrix 1:\n"; s1.display();
    cout << "\nMatrix 2:\n"; s2.display();

    SparseMatrix prod = s1.multiply(s2);
    cout << "\nProduct Matrix (Triplet Form):\n"; prod.display();
}
