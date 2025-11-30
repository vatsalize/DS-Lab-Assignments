// insertion sort

#include<iostream>

using namespace std;

int main(){

    int a[5]={5,4,2,3,1};
    
    cout<<"original:";
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    int i,j;

    for(i=1;i<5;i++){

        int key=a[i];
        j=i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }

    cout<<endl<<"after sorting by insertion sort:";
    for(i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}