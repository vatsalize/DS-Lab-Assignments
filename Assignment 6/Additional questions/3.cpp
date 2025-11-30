#include <bits/stdc++.h>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x) { data = x; prev = next = NULL; }
};

DNode* reverseInGroups(DNode* head, int k) {
    if (!head || k <= 1) return head;
    DNode* curr = head;
    DNode* newHead = NULL;
    DNode* prevTail = NULL;

    while (curr) {
        DNode* groupHead = curr;
        DNode* prev = NULL;
        int cnt = 0;

        while (curr && cnt < k) {
            DNode* nxt = curr->next;
            curr->next = prev;
            curr->prev = nxt;
            prev = curr;
            curr = nxt;
            cnt++;
        }

        if (!newHead) newHead = prev;

        if (prevTail) {
            prevTail->next = prev;
            prev->prev = prevTail;
        }

        groupHead->next = curr;
        if (curr) curr->prev = groupHead;

        prevTail = groupHead;
    }
    return newHead;
}

void printDLL(DNode* head) {
    DNode* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " <-> ";
        curr = curr->next;
    }
    cout << " <-> NULL" << endl;
}

DNode* buildList(initializer_list<int> vals) {
    DNode* head = NULL;
    DNode* tail = NULL;
    for (int v : vals) {
        DNode* node = new DNode(v);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}

int main() {
    DNode* head1 = buildList({1,2,3,4,5,6});
    int k1 = 2;
    cout << "Example 1:" << endl;
    cout << "Input:  ";
    printDLL(head1);
    head1 = reverseInGroups(head1, k1);
    cout << "Output: ";
    printDLL(head1);
    cout << endl;

    DNode* head2 = buildList({1,2,3,4,5,6});
    int k2 = 4;
    cout << "Example 2:" << endl;
    cout << "Input:  ";
    printDLL(head2);
    head2 = reverseInGroups(head2, k2);
    cout << "Output: ";
    printDLL(head2);

    return 0;
}
