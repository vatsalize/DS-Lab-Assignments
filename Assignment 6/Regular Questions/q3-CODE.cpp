// question 3

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    Node *head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertLast(int val) {
        Node *n = new Node(val);
        if (!head) head = n;
        else {
            Node *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    int size() {
        int count = 0;
        Node *temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
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

    int size() {
        if (!head) return 0;
        int count = 0;
        Node *temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }
};

int main() {
    DoublyLinkedList d;
    d.insertLast(10);
    d.insertLast(20);
    d.insertLast(30);
    cout << "Size of Doubly Linked List: " << d.size() << endl;

    CircularLinkedList c;
    c.insertLast(5);
    c.insertLast(15);
    c.insertLast(25);
    c.insertLast(35);
    cout << "Size of Circular Linked List: " << c.size() << endl;

    return 0;
}
