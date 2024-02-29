#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    int data[MAX];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> data[i];

    // bubble sort
    for (int i=n-1; i>0; i--) {
        for ( int j=0; j<i; j++ ) {
            if (data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }

    int k = 0;
    for (int i=1; i<n; i++) {
        if (data[i] != data[i-1])
            data[++k] = data[i];
    }
    for (int i=0; i<=k; i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}