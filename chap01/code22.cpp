#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n, k;
    int data[MAX];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> data[i];

    int count = 1, max_count = 1;
    for (int i=1; i<n; i++) {
        if (data[i] == data[i-1])
            count++;
        else
            count = 1;
        if (count > max_count)
            max_count = count;
    }
    cout << max_count << endl;
    return 0;
}  