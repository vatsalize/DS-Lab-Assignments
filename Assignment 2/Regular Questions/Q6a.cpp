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
                if (data[i].col == c) {
                    result.data[k++] = {data[i].col, data[i].row, data[i].val};
                }
            }
        }
        return result;
    }
};

int main() {
    int r, c, nz;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> r >> c >> nz;

    SparseMatrix s(r, c, nz);
    s.read();

    cout << "\nOriginal Matrix (Triplet Form):\n";
    s.display();

    SparseMatrix t = s.transpose();
    cout << "\nTranspose Matrix (Triplet Form):\n";
    t.display();
}
