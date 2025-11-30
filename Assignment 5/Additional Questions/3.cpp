#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

void removeLoop(Node* loop, Node* head) {
    Node* ptr1 = head;
    while (true) {
        Node* ptr2 = loop;
        while (ptr2->next != loop && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        if (ptr2->next == ptr1) break;
        ptr1 = ptr1->next;
    }
    Node* ptr2 = loop;
    while (ptr2->next != ptr1)
        ptr2 = ptr2->next;
    ptr2->next = NULL;
}

void detectAndRemove(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            removeLoop(slow, head);
            return;
        }
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(3);
    head->next->next->next = new Node(6);

    head->next->next->next->next = head->next; 

    detectAndRemove(head);

    printList(head);
    return 0;
}
