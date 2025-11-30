#include <iostream>
using namespace std;

void removeVowels(char str[], char result[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            result[j++] = ch;
        }
        i++;
    }
    result[j] = '\0'; 
}

int main() {
    char str[100], result[100];

    cout << "enter string: ";
    cin >> str;

    removeVowels(str, result);

    cout << "string after deleting vowels: " << result << endl;

    return 0;
}