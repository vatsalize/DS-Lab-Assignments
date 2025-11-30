#include <iostream>
using namespace std;
#define n 5 


class queue{

	int arr[n];
	int front,rear;
	
	public:
		
		queue() {
        front = rear = -1;
    	}
    	
    	bool isEmpty() {
        return (front == -1);
    	}

    	bool isFull() {
        return (rear == n - 1);
    	}
    	
		void enqueue(int x){
			
			if(isFull()) {
			cout<<"queue overflow.."<<endl; return;
		}
		
			else if (isEmpty()){
				front=rear=0;		
			}
				
			else rear++;
			
			arr[rear]=x;
			cout << x << " inserted into the queue." << endl;
		}
		
		void dequeue(){
			if(isEmpty()){
				cout<<"queue underflow.."<<endl;
				return;
			}
			
			else {
			
			cout<<arr[front]<<" is dequeued "<<endl;
			if(front==rear){
				front=rear=-1;	
			}
			else{
				
				front++;
			}}
		}

		
		int peek(){
			if(isEmpty()){
				cout<<"queue underflow..";
				return -1;
			}
			
			else return arr[front];
		}
		
		void display(){
			 if (isEmpty()) {
            cout << "Queue is empty!" <<endl;
            return;
       		 }
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			 cout << endl;
		}
	
};


int main() {
	
		int p;
		queue q;
	do{
	cout<<" operations on queue: "<<endl;
	cout<<"1. enqueue()"<<endl;
	cout<<"2. dequeue()"<<endl;
	cout<<"3. isEmpty() "<<endl;
	cout<<"4. isFull()"<<endl;
	cout<<"5. display()"<<endl;
	cout<<"6. peek()"<<endl;
	cout<<"7. exit()"<<endl;
	
	cout<<"choose: "<<endl;
	
	cin>>p;
	
	switch(p){
		case 1:{
			int val;
			cout<<"enter the value you want to enqueue :"<<endl;
			cin>>val; 
			q.enqueue(val);}
			break;
		
		case 2:{
			q.dequeue();
		}
			break;
		
		case 3:{
			if(q.isEmpty()) cout<<"empty"<<endl;
			else cout<<"not empty "<<endl;
		}break;
		
		case 4:{
			if(q.isFull()) cout<<"full"<<endl;
			else cout<<"not full "<<endl;
		}break;
		
		case 5:{
			q.display();
		}break;
		
		case 6: {
    		int val = q.peek();
    		if (val != -1) 
        	cout << "Front element: " << val << endl;
		} break;
		
		case 7:{
			cout<<"exiting..";
			
		}break;
		
		default: cout << "Invalid choice! Please try again." << endl;
	}
	
}while(p!=7);

return 0;
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//    q.display();
//    q.dequeue();
//    q.display();
//    cout << "Front element: " << q.peek() << endl;
}
