#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int val) {
        int sz = q.size();
        q.push(val);

        // Rotate the queue to bring new element to front
        for (int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << q.front() << " popped from stack" << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.pop();

    s.pop(); // underflow case

    return 0;
}

