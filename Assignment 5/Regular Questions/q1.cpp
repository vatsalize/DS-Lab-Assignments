#include <iostream>

using namespace std;

class node{
		public:

		int data;
		node*next;

		node(int val){
			data=val;
			next=NULL;
		}
	
};

class linkedlist{
	public:
		node*head;
		linkedlist(){
			head=NULL;
		}
		
		void insertionAtBeginning(int val){
			node* newnode= new node(val);
			if(head==NULL){
				head=newnode;
			}
			else{
				newnode->next=head;
				head=newnode;
			}
		}
		
		void insertionAtEnd(int val){
			node* newnode= new node(val);
			if(head==NULL){
				head=newnode;
				return;
			}
			node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
				temp->next=newnode;
		}
		
		void insertionAfterNode(int key,int val){
			node* newnode= new node(val);
			node*temp=head;
			while(temp->data!=key && temp!=NULL){
				temp=temp->next;
			}
				
				if(temp==NULL ){
					cout<<"invalid node";
					return;
				}
			newnode->next=temp->next;
			temp->next=newnode;	
				
		}
	
		
		void deleteFromBeginning(){
			node* temp=head;
			if(head==NULL){
				cout<<"ll is empty";
			}
			else if(head->next==NULL){
				head==NULL;
			}
			else{
			
				head=head->next;
			}
			
			delete temp;
		}
		
		void deleteFromEnd(){
			node*temp=head;
			if(head==NULL){
				cout<<"ll is empty";
			}
			else if(head->next==NULL){
			
				head==NULL;
			}
			else{
			
				node* prev=head;
				while(temp->next!=NULL){
				prev=temp;
				temp=temp->next;
				}
				prev->next=NULL;
			}
			delete temp;
		}
		
		void deleteNode(int val){
			node*temp=head;
			node*prev=NULL;
			
			 if (head == NULL) {
            cout << "ll is empty";
            return;
        	}
			while(temp->next!=NULL && temp->data!=val){
					prev=temp;
				temp=temp->next;
			}
				if(temp==NULL ){
					cout<<"invalid node";
					return;
				}
				else if(temp->next=NULL && temp->data==val){
						deleteFromEnd();
						}
				else if(head->data==val){
					deleteFromBeginning();
				}
				else{
					prev->next=temp->next;
				}
		
			delete temp;
		}
		
		int searchNode(int val){
			node* temp=head;
			int count=0;
			while(temp!=NULL ){
			if(temp->data==val){
					return count;
				}
				temp=temp->next;
				count++;
			}
			return -1;
		}
		
		void printll(){
		 node* temp = head;
        if (temp == NULL) {
            cout << "ll is empty";
            return;
        }
        while (temp != NULL) {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL";
		}
		
};

int main(){
	linkedlist ll;
	 int choice, val, key;

    while (true) {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display Linked List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            ll.insertionAtBeginning(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            ll.insertionAtEnd(val);
            break;

        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            ll.insertionAfterNode(key, val);
            break;

        case 4:
            ll.deleteFromBeginning();
            break;

        case 5:
            ll.deleteFromEnd();
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            ll.deleteNode(val);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            if (ll.searchNode(val) != -1)
                cout << "Node found at position " << ll.searchNode(val) << endl;
            else
                cout << "Node not found\n";
            break;

        case 8:
            ll.printll();
            break;

        case 9:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
	return 0;
	
}
