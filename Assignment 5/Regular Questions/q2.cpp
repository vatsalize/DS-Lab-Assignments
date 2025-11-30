#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedlist {
public:
    node* head;
    linkedlist() {
        head = NULL;
    }

    void insertionAtBeginning(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }

    void insertionAtEnd(int val) {
        node* newnode = new node(val);
        if (head == NULL) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "ll is empty";
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "ll is empty";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        node* temp = head;
        node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
    }

    void deleteNode(int val) {
        if (head == NULL) {
            return;
        }

        if (head->data == val) {
            deleteFromBeginning();
            return;
        }

        node* temp = head;
        node* prev = NULL;

        while (temp != NULL && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        if (temp->next == NULL) {
            deleteFromEnd();
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void printll() {
        node* temp = head;
        if (temp == NULL) {
            cout << "ll is empty";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void update(int val) {
        int count = 0;
        while (true) {
            node* temp = head;
            bool found = false;

            while (temp != NULL) {
                if (temp->data == val) {
                    deleteNode(val);
                    count++;
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            if (!found)
                break;
        }
        cout << "Count: " << count << endl;
    }
};

int main() {
    linkedlist l;
    l.insertionAtEnd(1);
    l.insertionAtEnd(2);
    l.insertionAtEnd(1);
    l.insertionAtEnd(2);
    l.insertionAtEnd(1);
    l.insertionAtEnd(3);
    l.insertionAtEnd(1);
    l.printll();
    l.update(1);
    l.printll();
}

