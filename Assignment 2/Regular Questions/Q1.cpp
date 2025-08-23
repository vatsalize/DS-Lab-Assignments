#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) 
            return mid;    
        else if (arr[mid] < target) 
            low = mid + 1; 
        else 
            high = mid - 1;                      
    }
    return -1;
}

int main() {
    int n, target;
    cout << "enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "enter elements in sorted order: ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i]; 

    cout << "enter element to search: ";
    cin >> target;             
    
    int result = binarySearch(arr, n, target);
    if (result != -1)
        cout << "element " << target << "found at index " << result;
    else
        cout << "element " << target << "not found";

    return 0;
}