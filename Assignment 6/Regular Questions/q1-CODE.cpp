// question 1

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

    void insertFirst(int val) {
        Node *n = new Node(val);
        if (!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

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

    void insertAfter(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node *n = new Node(val);
        n->next = temp->next;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }

    void insertBefore(int key, int val) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node *n = new Node(val);
        n->next = temp;
        n->prev = temp->prev;
        if (temp->prev) temp->prev->next = n;
        else head = n;
        temp->prev = n;
    }

    void deleteNode(int key) {
        Node *temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int key) {
        Node *temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularLinkedList {
    Node *head;
public:
    CircularLinkedList() { head = NULL; }

    void insertFirst(int val) {
        Node *n = new Node(val);
        if (!head) {
            head = n;
            n->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) temp = temp->next;
            n->next = head;
            temp->next = n;
            head = n;
        }
    }

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

    void insertAfter(int key, int val) {
        if (!head) return;
        Node *temp = head;
        do {
            if (temp->data == key) {
                Node *n = new Node(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void insertBefore(int key, int val) {
        if (!head) return;
        Node *temp = head, *prev = NULL;
        do {
            if (temp->data == key) {
                Node *n = new Node(val);
                if (temp == head) {
                    Node *last = head;
                    while (last->next != head) last = last->next;
                    n->next = head;
                    last->next = n;
                    head = n;
                } else {
                    n->next = temp;
                    prev->next = n;
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *curr = head, *prev = NULL;
        do {
            if (curr->data == key) {
                if (curr == head) {
                    Node *last = head;
                    while (last->next != head) last = last->next;
                    if (head == head->next) head = NULL;
                    else {
                        last->next = head->next;
                        head = head->next;
                    }
                } else prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    bool search(int key) {
        if (!head) return false;
        Node *temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void display() {
        if (!head) return;
        Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList d;
    CircularLinkedList c;
    int ch, type, val, key;
    while (true) {
        cout << "1.Doubly 2.Circular 3.Exit: ";
        cin >> type;
        if (type == 3) break;
        cout << "1.InsertFirst 2.InsertLast 3.InsertAfter 4.InsertBefore 5.Delete 6.Search 7.Display 8.Back: ";
        while (true) {
            cin >> ch;
            if (ch == 8) break;
            if (type == 1) {
                switch (ch) {
                    case 1: cin >> val; d.insertFirst(val); break;
                    case 2: cin >> val; d.insertLast(val); break;
                    case 3: cin >> key >> val; d.insertAfter(key,val); break;
                    case 4: cin >> key >> val; d.insertBefore(key,val); break;
                    case 5: cin >> key; d.deleteNode(key); break;
                    case 6: cin >> key; cout << (d.search(key) ? "Found" : "Not Found") << endl; break;
                    case 7: d.display(); break;
                }
            } else if (type == 2) {
                switch (ch) {
                    case 1: cin >> val; c.insertFirst(val); break;
                    case 2: cin >> val; c.insertLast(val); break;
                    case 3: cin >> key >> val; c.insertAfter(key,val); break;
                    case 4: cin >> key >> val; c.insertBefore(key,val); break;
                    case 5: cin >> key; c.deleteNode(key); break;
                    case 6: cin >> key; cout << (c.search(key) ? "Found" : "Not Found") << endl; break;
                    case 7: c.display(); break;
                }
            }
        }
    }
    return 0;
}
