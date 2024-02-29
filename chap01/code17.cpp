#include <iostream>
using namespace std;

const int MAX = 100;  // #define MAX 100

int main() {

    int data[MAX];

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> data[i];

    int sum = 0, max = data[0];
    for (int i=0; i<n; i++)  {
        sum += data[i];
        if (data[i] > max)
            max = data[i];
    }

    cout << "The sum is " << sum << " and the maximum is " << max << endl;
    return 0;
}