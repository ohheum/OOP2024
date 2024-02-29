#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> words;
    string str;
    while(true) {
        cin >> str;
        if (str == "exit")
            break;
        words.push_back(str);
    }

    sort(words.begin(), words.end());

    for (auto s: words)
        cout << s << " ";
    cout << endl;
    return 0;
}