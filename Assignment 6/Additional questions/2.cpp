#include <bits/stdc++.h>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int x) { data = x; next = NULL; }
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x) { data = x; prev = next = NULL; }
};

int parity(int n) {
    int c = 0;
    while (n) { n &= (n - 1); c++; }
    return c;
}

CNode* removeEvenParityCSLL(CNode* head) {
    if (!head) return NULL;
    CNode* curr = head;
    CNode* prev = NULL;

    do {
        if (parity(curr->data) % 2 == 0) {
            if (curr == head) {
                CNode* temp = head;
                while (temp->next != head) temp = temp->next;
                if (head->next == head) return NULL;
                temp->next = head->next;
                head = head->next;
                delete curr;
                curr = head;
                continue;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    return head;
}

DNode* removeEvenParityDLL(DNode* head) {
    DNode* curr = head;
    while (curr) {
        if (parity(curr->data) % 2 == 0) {
            if (curr == head) {
                head = head->next;
                if (head) head->prev = NULL;
                DNode* del = curr;
                curr = curr->next;
                delete del;
                continue;
            } else {
                curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                DNode* del = curr;
                curr = curr->next;
                delete del;
                continue;
            }
        }
        curr = curr->next;
    }
    return head;
}

void printCSLL(CNode* head) {
    if (!head) return;
    CNode* t = head;
    do { cout << t->data << " "; t = t->next; } while (t != head);
}

void printDLL(DNode* head) {
    while (head) { cout << head->data << " "; head = head->next; }
}

int main() {

    cout << "Input (Circular Linked List): 9 -> 11 -> 34 -> 6 -> 13 -> 21" << endl;
    cout << "Input (Doubly Linked List): 18 <-> 15 <-> 8 <-> 9 <-> 14" << endl << endl;

    CNode* h1 = new CNode(9);
    h1->next = new CNode(11);
    h1->next->next = new CNode(34);
    h1->next->next->next = new CNode(6);
    h1->next->next->next->next = new CNode(13);
    h1->next->next->next->next->next = new CNode(21);
    h1->next->next->next->next->next->next = h1;

    h1 = removeEvenParityCSLL(h1);

    cout << "Output (Circular Linked List): ";
    printCSLL(h1);
    cout << endl;

    DNode* h2 = new DNode(18);
    h2->next = new DNode(15); h2->next->prev = h2;
    h2->next->next = new DNode(8); h2->next->next->prev = h2->next;
    h2->next->next->next = new DNode(9); h2->next->next->next->prev = h2->next->next;
    h2->next->next->next->next = new DNode(14); h2->next->next->next->next->prev = h2->next->next->next;

    h2 = removeEvenParityDLL(h2);

    cout << "Output (Doubly Linked List): ";
    printDLL(h2);
    cout << endl;

    return 0;
}
