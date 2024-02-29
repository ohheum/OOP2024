#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n, k;
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
    cout << "Sorted data:";
    for (int i=0; i<n; i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}