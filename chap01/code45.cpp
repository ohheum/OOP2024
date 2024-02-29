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
        auto it=words.begin();
        while (it!=words.end() && *it < str)
            it++;
        if (it==words.end())
            words.push_back(str);
        else
            words.insert(it, str);

        for (auto s: words)
            cout << s << " ";
        cout << endl;
    }
    return 0;
}