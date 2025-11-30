// question 4

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node *next, *prev;
    Node(char val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
    Node *head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertLast(char val) {
        Node *n = new Node(val);
        if (!head) head = n;
        else {
            Node *temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;

        Node *left = head;
        Node *right = head;

        while (right->next) right = right->next;

        while (left != right && right->next != left) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void clear() {
        head = NULL;
    }
};

int main() {
    DoublyLinkedList d;

    string s1 = "DATASTRUCTURE";
    for (char ch : s1) d.insertLast(ch);
    cout << s1 << " : " << (d.isPalindrome() ? "Palindrome" : "Not Palindrome") << endl;

    d.clear();

    string s2 = "MADAM";
    for (char ch : s2) d.insertLast(ch);
    cout << s2 << " : " << (d.isPalindrome() ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
