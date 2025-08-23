#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string a, string b) {
    return b.find(a) != string::npos;
}

bool canSplit(string s) {
    int n = s.length();
    // split points i, j (1 ≤ i < j < n)
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            string A = s.substr(0, i);
            string B = s.substr(i, j-i);
            string C = s.substr(j);

            // check all 3 cases
            if (isSubstring(A, B) && isSubstring(A, C)) return true;
            if (isSubstring(B, A) && isSubstring(B, C)) return true;
            if (isSubstring(C, A) && isSubstring(C, B)) return true;
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (canSplit(s)) cout << "YES, it can be split as required.\n";
    else cout << "NO, it cannot be split.\n";
}
