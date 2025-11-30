#include <iostream>
#include <stack>
using namespace std;

int main() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);
    int answer[n] = {0};
    stack<int> s;  // stores indices of temperatures

    for (int i = 0; i < n; i++) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int idx = s.top();
            s.pop();
            answer[idx] = i - idx;
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
