#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int MAX = 1000;

int main() {
    ifstream infile("input35.txt");
    string str;
    string words[MAX];
    int n = 0;
    while(infile >> str) {
        int s = 0, t = str.length()-1;
        while(s<str.length() && !isalnum(str[s]))
            s++;
        while(t>=0 && !isalnum(str[t]))
            t--;
        if (s<=t) {
            string pure_word = str.substr(s, t-s+1);
            for (int i=0; i<pure_word.length(); i++)
                pure_word[i] = tolower(pure_word[i]);
            bool found = false;
            for (int i=0; i<n; i++) {
                if (words[i] == pure_word) {
                    found = true;
                    break;
                }
            }
            if (!found)
                words[n++] = pure_word;
        }
    }
    infile.close();
    for (int i=0; i<n; i++)
        cout << words[i] << endl;
    return 0;
}
