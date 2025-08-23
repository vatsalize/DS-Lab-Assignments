#include <iostream>
using namespace std;

void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char str[100];
    cout << "enter string in uppercase: ";
    cin >> str;

    toLowercase(str);

    cout << "lowercase string: " << str;
    return 0;
}