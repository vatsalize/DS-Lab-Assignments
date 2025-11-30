// question 6

#include<iostream>

using namespace std;

class item{
    
    public:

    int data;
    int priority;
};

const int max_size=100;

class priority_queue{

    item arr[max_size];
    int size;

    public:

    priority_queue(){
        size=-1;
    }

    void enqueue(int data,int priority){
        if(size==max_size-1){
            cout<<"priority queue is full so cannot insert element"<<endl;
            return;
        }

        size++;
        arr[size].data=data;
        arr[size].priority=priority;

        int i=size;
        while(i>0 && arr[(i-1)/2].priority<arr[i].priority){
            item temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;

            i=(i-1)/2;
        }
    }

    void dequeue(){
        if(size==-1){
            cout<<"priority queue is empty so cannot delete element"<<endl;
            return;
        }

        cout<<"dequeued: data="<<arr[0].data<<",priority="<<arr[0].priority<<endl;

        arr[0]=arr[size];
        size--;

        int i=0;

        while(true){
            int left=2*i+1;
            int right=2*i+2;
            int largest=i;

            if(left<=size && arr[left].priority>arr[largest].priority){
                largest=left;
            }
            if(right<=size && arr[right].priority>arr[largest].priority){
                largest=right;
            }

            if(largest!=i){
                item temp=arr[i];
                arr[i]=arr[largest];
                arr[largest]=temp;

                i=largest;
            }
            else{
                break;
            }
        }
    }

    item peek(){
        if(size==-1){
            cout<<"priority queue is empty"<<endl;
            return {-1,-1};
        }
        return arr[0];
    }

    bool isEmpty(){
        if(size==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"priority queue is empty so cannot display"<<endl;
            return;
        }
        cout<<"priority queue elements:";
        
        for(int i=0;i<=size;i++){
            cout<<"("<<arr[i].data<<","<<arr[i].priority<<")"<<" ";
        }
        cout<<endl;
    }
};

int main(){
    
    priority_queue pq;

    pq.enqueue(10,2);
    pq.enqueue(20,5);
    pq.enqueue(5,1);
    pq.enqueue(30,8);

    pq.display();

    pq.dequeue();
    pq.display();

    item top=pq.peek();
    if(top.data!=-1){
        cout<<"top element: data="<<top.data<<",priority="<<top.priority<<endl;
    }

    pq.dequeue();
    pq.dequeue();
    pq.dequeue();
    pq.dequeue();

    pq.display();
    
    return 0;
}