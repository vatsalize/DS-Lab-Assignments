#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

void splitList(Node* head, Node*& head1, Node*& head2) {
    if (!head || head->next == head) {
        head1 = head;
        head2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head) fast = fast->next;

    head1 = head;
    head2 = slow->next;

    slow->next = head1;
    fast->next = head2;
}

void printCircular(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data;
        temp = temp->next;
        if (temp != head) cout << "->";
    } while (temp != head);
}

int main() {
    Node* head = new Node(10);
    Node* n2 = new Node(4);
    Node* n3 = new Node(9);

    head->next = n2;
    n2->next = n3;
    n3->next = head;

    Node *head1 = NULL, *head2 = NULL;
    splitList(head, head1, head2);

    printCircular(head1);
    cout << " , ";
    printCircular(head2);

    return 0;
}
