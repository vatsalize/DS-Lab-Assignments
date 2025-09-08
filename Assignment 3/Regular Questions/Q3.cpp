#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string expr) 
{
    stack<char> s;
    for (char ch : expr) 
    {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}
int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Expression is balanced.\n";
    else
        cout << "Expression is NOT balanced.\n";
    return 0;
}