#include <iostream>
#include <stack>
using namespace std;

bool canSortUsingStack(int A[], int N) {
    stack<int> S;
    int B[N];
    int bIndex = 0;
    int expected = 1;  // assuming elements are from 1 to N in some order

    for (int i = 0; i < N; i++) {
        S.push(A[i]);

        while (!S.empty() && S.top() == expected) {
            B[bIndex++] = S.top();
            S.pop();
            expected++;
        }
    }

    while (!S.empty()) {
        if (S.top() != expected) return false;
        B[bIndex++] = S.top();
        S.pop();
        expected++;
    }

    return true;
}

int main() {
    int A[] = {4, 1, 3, 2};
    int N = sizeof(A) / sizeof(A[0]);

    if (canSortUsingStack(A, N)) {
        cout << "Yes, it's possible to sort array B in ascending order." << endl;
    } else {
        cout << "No, it's not possible." << endl;
    }

    return 0;
}
