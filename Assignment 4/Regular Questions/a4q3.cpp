#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
 int main(){
 	int n=6;
 	queue<int> q;
 	q.push(4);
 	q.push(7);
	q.push(11);
 	q.push(20);
 	q.push(5);
 	q.push(9);
 	
 	queue<int>q1;
 	for(int i=0;i<n/2;i++){
		q1.push(q.front());
		q.pop();
	}
	
	while(!q1.empty()){
		q.push(q1.front());
		q1.pop();
		q.push(q.front());
		q.pop();
		
	}
	
	 while(!q.empty()){
	 	cout<<q.front()<<" ";
	 q.pop();
	 }
	 
 	
 	
// 	int n=6;
// 	stack<int> s;
// 	
// 	for(int i=0;i<n/2;i++){
// 		s.push(q.front());
// 		q.pop();
//	 }
//	 
//	 while(!s.empty()){
//	 	q.push(s.top());
//	 	s.pop();
//	 }
//	 
//	 for(int i=0;i<n/2;i++){
//	 	q.push(q.front());
//	 	q.pop();
//	 }
//	 
//	 for(int i=0;i<n/2;i++){
//	 	s.push(q.front());
//	 	q.pop();
//	 }
//	 
//	 while(!s.empty()){
//	 	q.push(s.top());
//	 	s.pop();
//	 	q.push(q.front());
//	 	q.pop();
//	 }
//	 
//	 while(!q.empty()){
//	 	cout<<q.front()<<" ";
//		 q.pop();
//	 }
//	 
	 
 }
 
