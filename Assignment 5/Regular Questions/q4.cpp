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
    
    node* reverselist(){
    	node*cur=head;
    	node*next=NULL;
    	node*prev=NULL;
    	while(cur!=NULL){
    		next=cur->next;
    		cur->next=prev;
    		prev=cur;
    		cur=next;
		}
		head=prev;
		return head;	
	}
};
int main(){
	linkedlist l;
	l.insertionAtEnd(1);
    l.insertionAtEnd(2);
    l.insertionAtEnd(3);
    l.insertionAtEnd(4);
    l.printll();
    l.reverselist();
    l.printll();
}
