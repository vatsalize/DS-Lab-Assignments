#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) { data = x; next = prev = NULL; }
};

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL" << endl;
}

Node* fixRandomPointer(Node* head) {
    vector<Node*> arr;
    Node* temp = head;

    while (temp) {
        arr.push_back(temp);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end(), [](Node* a, Node* b){
        return a->data < b->data;
    });

    for (int i = 0; i < arr.size(); i++) {
        arr[i]->next = (i + 1 < arr.size() ? arr[i+1] : NULL);
        arr[i]->prev = (i - 1 >= 0 ? arr[i-1] : NULL);
    }

    return arr[0];
}

int main() {
    cout << "Input:" << endl;
    cout << "1 <-> 2 <-> 3, but 1->next points to 3 instead of 2" << endl << endl;

    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    head->next = n3;  // wrong random pointer
    n3->prev = head;

    n3->next = n2;
    n2->prev = n3;

    cout << "Output:" << endl;
    head = fixRandomPointer(head);
    printList(head);

    return 0;
}
