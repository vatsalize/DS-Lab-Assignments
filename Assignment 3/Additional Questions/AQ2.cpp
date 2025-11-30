#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    int minElement;

public:
    MinStack() {}

    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minElement = x;
        } else {
            if (x >= minElement) {
                s.push(x);
            } else {
                s.push(2 * x - minElement);
                minElement = x;
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        int top = s.top();
        s.pop();

        if (top < minElement) {
            minElement = 2 * minElement - top;
        }
    }

    int top() {
        int top = s.top();
        if (top >= minElement) return top;
        else return minElement;
    }

    int getMin() {
        return minElement;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(2);
    ms.push(10);
    ms.push(1);

    cout << "Minimum: " << ms.getMin() << endl;
    ms.pop();
    cout << "Top element: " << ms.top() << endl;
    cout << "Minimum: " << ms.getMin() << endl;
    ms.pop();
    cout << "Minimum: " << ms.getMin() << endl;

    return 0;
}
