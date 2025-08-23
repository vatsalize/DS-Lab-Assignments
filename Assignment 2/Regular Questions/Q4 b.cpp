#include <iostream>
using namespace std;

void reverseString(char str[]) {
    int len = 0;
    
    while (str[len] != '\0') {
        len++;
    }

    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
}

int main() {
    char str[100];

    cout << "enter string: ";
    cin >> str;

    cout << "reversed string: ";
    reverseString(str);
    cout << endl;

    return 0;
}