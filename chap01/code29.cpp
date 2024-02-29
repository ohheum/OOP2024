#include <iostream>
using namespace std;

int main() {
    string text;

    while(true) {
        getline(cin, text);
        if (text == "exit")
            break;

        cout << text << ":" << text.length() << endl;
    }
    return 0;
} 