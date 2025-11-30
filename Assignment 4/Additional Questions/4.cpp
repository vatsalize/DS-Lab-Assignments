#include <bits/stdc++.h>
using namespace std;

int countStudentsUnableToEat(int n, int students[], int sandwiches[]) {
    queue<int> q;
    for (int i = 0; i < n; ++i) q.push(students[i]);

    int i = 0;
    int rotations = 0;

    while (!q.empty() && i < n) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            ++i;
            rotations = 0;
        } else {
            int front = q.front();
            q.pop();
            q.push(front);
            ++rotations;
            if (rotations == (int)q.size()) break;
        }
    }
    return q.size();
}

int main() {
    int n = 4;
    int students[4] = {1, 1, 0, 0};
    int sandwiches[4] = {0, 1, 0, 1};

    cout << countStudentsUnableToEat(n, students, sandwiches);
    return 0;
}
