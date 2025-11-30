#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string s){
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        char c = s[i];
        
        if(isdigit(c)){
            st.push(c - '0');  
        }
        else{
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();

            switch(c){
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> exp;

    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
