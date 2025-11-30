#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;

    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    temp->next = head;
    k = k % len;

    while (k--) temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 4;
    head = rotateLeft(head, k);

    printList(head);
    return 0;
}
