// question 5

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

class LinkedList {
public:
    Node *head;
    LinkedList() { head = NULL; }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (!head) head = n;
        else {
            Node *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
        }
    }

    void makeCircular() {
        if (!head) return;
        Node *temp = head;
        while (temp->next) temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (!head) return false;
        Node *temp = head->next;
        while (temp && temp != head) temp = temp->next;
        return (temp == head);
    }
};

int main() {
    LinkedList l;
    l.insertLast(10);
    l.insertLast(20);
    l.insertLast(30);
    l.insertLast(40);

    cout << (l.isCircular() ? "Circular Linked List" : "Not Circular") << endl;

    l.makeCircular();
    cout << (l.isCircular() ? "Circular Linked List" : "Not Circular") << endl;

    return 0;
}
