#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;

int main()
{
    string words[MAX], str;
    int count[MAX] = { 0 };
    int n, k=0;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> str;

        int j = 0;
        for (; j<k; j++)
            if (words[j] == str)
                break;

        if (j < k)
            count[j]++;
        else {
            words[k] = str;
            count[k++] = 1;
        }
    }

    for (int i=0; i<k; i++)
        cout << words[i] << " " << count[i] << endl;

    return 0;
}