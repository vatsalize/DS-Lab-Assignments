// selection sort

#include<iostream>

using namespace std;

int main(){

    int a[5]={4,5,3,2,1};
    int i,j;

    cout<<"original:";
    for(i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    for(i=0;i<4;i++){
        
        int min_index=i;

        for(j=i+1;j<5;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }

        int temp;
        temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;
    }

    cout<<endl<<"after sorting by selection sort:";
    for(i=0;i<5;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}