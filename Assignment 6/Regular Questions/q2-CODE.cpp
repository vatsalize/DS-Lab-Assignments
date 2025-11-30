// question 2

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node *head;
public:
    CircularLinkedList() { head = NULL; }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }

    void displayWithHeadRepeat() {
        if (!head) return;
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList c;
    c.insertLast(20);
    c.insertLast(100);
    c.insertLast(40);
    c.insertLast(80);
    c.insertLast(60);

    c.displayWithHeadRepeat();
    return 0;
}
