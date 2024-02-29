#include <iostream>
using namespace std;

int main() {
    int number = 123, input=-1;
    cout << "Please enter an integer: ";

    cin >> input;
    cout << input << endl;
    if (input == number)
        cout << "Numbers match! :-)" << endl;
    else
        cout << "Numbers do not match! :-(" << endl;

    return 0;
} 