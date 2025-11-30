#include <bits/stdc++.h>
using namespace std;

void insertSorted(queue<int> &q, int val) {
    if (q.empty() || q.front() >= val) {
        q.push(val);
        return;
    }
    int temp = q.front();
    q.pop();
    insertSorted(q, val);
    q.push(temp);
}

void sortQueue(queue<int> &q) {
    if (q.empty()) return;
    int temp = q.front();
    q.pop();
    sortQueue(q);
    insertSorted(q, temp);
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
