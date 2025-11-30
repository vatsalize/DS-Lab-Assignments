#include <iostream>
using namespace std;

class Stack
{
    static const int max = 5;
    int arr[max];
    int top = -1;

public:
    void push(int num)
    {
        if (top == max - 1){
            cout << "\nStack Full~~";
        }else{
            top++;
            arr[top]=num;
        }            
    }
    void pop()
    {
        int popped;
        if (top == -1)
            cout << "\nNot possible , stack is empty :(";
        else
       { popped = arr[top];
        top--;
        cout<<"The number popped out is\n"<<popped;}
    }
    int peek()
    {
        if (top == -1)
            cout << "\nNot possible , stack is empty :(";
        int above = arr[top];
        return above;
    }
    void isEmpty()
    {
        if (top == -1)
            cout << "\nstack is empty :(";
        else
            cout << "\nstack is not empty :)";
    }
    void isFull()
    {
        if (top == max-1)
            cout << "\nStack Full~~";
        else
            cout << "\nstack not Full :o";
    }
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Stack s;
    int choice, value;
    while(choice!=7)
    {
        cout << "\n  ---Stack Menu---  \n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter a number\n";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.isFull();
            break;
        case 6:
            s.display();
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    cout << "Exiting program.\n";
    return 0;
}