#include <iostream>
#include <stack>
using namespace std;

int main() {
    int A[] = {4, 5, 2, 10, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int result[n];
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }
        if (s.empty()) result[i] = -1;
        else result[i] = s.top();
        s.push(A[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
