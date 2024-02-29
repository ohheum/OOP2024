#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    int data[MAX];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> data[i];

    int s;
    cin >> s;
    int count = 0;
    for ( int i=0; i<n-1; i++) {
        for ( int j=i+1; j<n; j++ ) {  // i<j
            if (data[i] + data[j] == s)
                count++;
        }
    }
    cout << count << endl;

    return 0;
}