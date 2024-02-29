#include <iostream>
using namespace std;
const int MAX = 100;

void bubble_sort(int n, int data[]);

int main() {
    int data[MAX], n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> data[i];

    bubble_sort(n, data);

    for (int i=0; i<n; i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}

void bubble_sort(int n, int data[]) {
    for ( int i=n-1; i>0; i--) {
        for ( int j=0; j<i; j++ ) {
            if (data[j] > data[j+1]) {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}

