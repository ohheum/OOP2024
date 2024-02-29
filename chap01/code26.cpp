#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    int mat[MAX][MAX];
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> mat[i][j];

    for (int j=0; j<n; j++) {
        for (int i=0; i<n; i++)
            cout << mat[i][j] << " ";
    }
    return 0;
} 