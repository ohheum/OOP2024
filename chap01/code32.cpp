#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    string words[MAX], pattern;
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> words[i];
    cin >> pattern;

    for (int i=0; i<N; i++) {

        int index = words[i].find(pattern);

        if (index > -1)
            cout << words[i] << endl;
    }
    return 0;
}