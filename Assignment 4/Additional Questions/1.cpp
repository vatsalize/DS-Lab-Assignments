#include <bits/stdc++.h>
using namespace std;

string toBinary(int x) {
    string s;
    while (x > 0) {
        s.push_back((x & 1) + '0');
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) {
        cout << toBinary(i);
        if (i != n) cout << " ";
    }
    return 0;
}
