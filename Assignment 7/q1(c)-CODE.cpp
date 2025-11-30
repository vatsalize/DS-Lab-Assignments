// bubble sort

#include<iostream>

using namespace std;

int main(){

    int a[5]={5,4,3,2,1};
    int i,j;
    cout<<"original:";
    for(i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    int temp;

    for(i=0;i<5;i++){
        for(j=0;j<4-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
    cout<<endl;
    cout<<"after sorting bubble sort";
    for(i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}