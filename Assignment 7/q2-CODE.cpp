// question 2

#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n){
    int start = 0, end = n - 1;

    while(start < end){
        int minIndex = start;
        int maxIndex = start;

        for(int i = start; i <= end; i++){
            if(arr[i] < arr[minIndex])
                minIndex = i;
            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[start], arr[minIndex]);

        if(maxIndex == start)
            maxIndex = minIndex;

        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11, 90};
    cout<<"original array:";
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int n = sizeof(arr)/sizeof(arr[0]);

    improvedSelectionSort(arr, n);

    cout<<"after sorting:";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
