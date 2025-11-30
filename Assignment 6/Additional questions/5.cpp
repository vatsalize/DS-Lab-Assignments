#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *right, *left, *up, *down;
    Node(int x) { data = x; right = left = up = down = NULL; }
};

Node* constructFromMatrix(int mat[][3], int m, int n) {
    vector<vector<Node*>> node(m, vector<Node*>(n, NULL));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            node[i][j] = new Node(mat[i][j]);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                node[i][j]->right = node[i][j+1];
                node[i][j+1]->left = node[i][j];
            }
            if (i + 1 < m) {
                node[i][j]->down = node[i+1][j];
                node[i+1][j]->up = node[i][j];
            }
        }
    }
    return node[0][0];
}

void printRows(Node* head, int m, int n) {
    Node* rowStart = head;
    for (int i = 0; i < m; i++) {
        Node* curr = rowStart;
        while (curr) {
            cout << curr->data;
            if (curr->right) cout << " <-> ";
            else cout << " <-> NULL";
            curr = curr->right;
        }
        cout << endl;
        rowStart = rowStart->down;
    }
}

int main() {
    int mat[3][3] = { {1,2,3},
                      {4,5,6},
                      {7,8,9} };

    cout << "Input 2D matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
    cout << endl << "Output (row-wise next/prev links):" << endl;

    Node* head = constructFromMatrix(mat, 3, 3);
    printRows(head, 3, 3);

    return 0;
}
