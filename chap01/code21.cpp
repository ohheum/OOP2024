#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    int data[MAX];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> data[i];

    int maxSum = data[0];
    for (int i=0; i<n; i++)  {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += data[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << "The max sum is " << maxSum << endl;
    return 0;
}