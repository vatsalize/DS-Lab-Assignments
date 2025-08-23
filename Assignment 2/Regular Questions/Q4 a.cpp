#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);   
    cout << "Enter second string: ";
    getline(cin, str2);
    
    string result = str1 + str2;
    cout << "Concatenated String: " << result << endl;
    return 0;
}
