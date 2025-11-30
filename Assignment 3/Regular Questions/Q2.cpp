#include <iostream>
#include <stack>
using namespace std;
int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    stack<char> s;
    for (int i = 0; i < word.length(); i++) {
        s.push(word[i]);
    }

    cout << "Reversed word: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}