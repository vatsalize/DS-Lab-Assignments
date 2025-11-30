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
    
    void middle(){
    	node*slow=head;
    	node* fast=head;
    	while(fast!=NULL && fast->next!=NULL){
    		slow=slow->next;
    		fast=fast->next->next;
		}
		cout<<slow->data;
	}
};
int main(){
	linkedlist l;
	l.insertionAtEnd(1);
    l.insertionAtEnd(2);
    l.insertionAtEnd(3);
    l.insertionAtEnd(4);
    l.insertionAtEnd(5);
	l.middle();
}
