#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    cin >> str;

    for (int i=0; i<str.length()/2; i++) {
        if (tolower(str.at(i)) != tolower(str.at(str.length()-i-1))) {
            cout << "Not palindrome." << endl;
            return 0;
        }
    }
    cout << "Palindrome." << endl;
    return 0;
}