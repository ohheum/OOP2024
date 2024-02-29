#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> words;
    string str;
    vector<int> count;

    while(cin >> str) {
        int j = 0;
        for (; j<words.size(); j++)
            if (words[j] == str)
                break;

        if (j < words.size())
            count[j]++;
        else {
            words.push_back(str);
            count.push_back(1);
        }
    }

    for (int i=0; i<words.size(); i++)
        cout << words[i] << " " << count[i] << endl;

    return 0;
}

