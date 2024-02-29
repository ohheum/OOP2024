#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;

int main()
{
    string words[MAX];

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> words[i];

    string str1, str2;
    cin >> str1 >> str2;

    for (int i=0; i<n; i++)  {
        if (words[i] >= str1 && words[i] <= str2) {
            cout << words[i] << endl;
        }
    }
    return 0;
}

