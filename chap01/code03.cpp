#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout <<"Please type a string: ";

    cin >> input;

    if (input == "hello")
        cout << "Strings match! :-)" << endl;
    else
        cout << "Strings do not match! :-(" << endl;

    return 0;
}