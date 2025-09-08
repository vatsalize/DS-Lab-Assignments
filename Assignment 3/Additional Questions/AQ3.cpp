#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int nge[n];
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}
