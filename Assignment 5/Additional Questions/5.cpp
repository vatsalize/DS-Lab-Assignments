#include <bits/stdc++.h>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
    Node(int c, int p) { coeff = c; power = p; next = NULL; }
};

Node* addPoly(Node* p1, Node* p2) {
    Node dummy(0, 0);
    Node* tail = &dummy;

    while (p1 && p2) {
        if (p1->power == p2->power) {
            int c = p1->coeff + p2->coeff;
            if (c != 0) {
                tail->next = new Node(c, p1->power);
                tail = tail->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->power > p2->power) {
            tail->next = new Node(p1->coeff, p1->power);
            tail = tail->next;
            p1 = p1->next;
        } else {
            tail->next = new Node(p2->coeff, p2->power);
            tail = tail->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        tail->next = new Node(p1->coeff, p1->power);
        tail = tail->next;
        p1 = p1->next;
    }
    while (p2) {
        tail->next = new Node(p2->coeff, p2->power);
        tail = tail->next;
        p2 = p2->next;
    }
    return dummy.next;
}

void printPoly(Node* head) {
    while (head) {
        cout << "[" << head->coeff << ", " << head->power << "]";
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = new Node(5, 2);
    list1->next = new Node(4, 1);
    list1->next->next = new Node(2, 0);

    Node* list2 = new Node(5, 1);
    list2->next = new Node(5, 0);

    Node* result = addPoly(list1, list2);
    printPoly(result);
    return 0;
}
