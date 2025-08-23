#include<iostream>
using namespace std;

int arr[100]; 
int n;

void create() {
    cout << "enter size: ";
    cin >> n;
    cout << "enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    cout << "array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " << endl;
    }
}

void insert() {
    int pos, value;
    cout << "enter position and value: ";
    cin >> pos >> value;
    if (pos < 0 || pos > n) {
        cout << "wrong position" << endl;
        return;
    }

    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = value;
    n++;
}

void Delete() {
    int pos;
    cout << "enter position which is to be deleted: ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "wrong position" << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void linear_search() {
    int searchElement;
    cout << "enter element which is to be searched: ";
    cin >> searchElement;
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchElement) {
            cout << "element found at index " << i << endl;
            return;
        }
    }
    cout << "element not found" << endl;
}

int main() {
    int select;

    while (true) {
        cout << "menu" << endl;
        cout << "1. create" << endl;
        cout << "2. display" << endl;
        cout << "3. insert" << endl;
        cout << "4. delete" << endl;
        cout << "5. linear search" << endl;
        cout << "6. exit" << endl;
        cout << "enter your choice: ";
        cin >> select;

        switch (select) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: Delete(); break;
            case 5: linear_search(); break;
            case 6: exit(0);
            default: cout << "you entered a wrong choice" << endl;
        }
    }
}