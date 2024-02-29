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

    int row_sum[MAX] = {0}, col_sum[MAX] = {0};
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            row_sum[i] += mat[i][j];

    for (int j=0; j<n; j++)
        for (int i=0; i<n; i++)
            col_sum[j] += mat[i][j];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << mat[i][j] << " ";
        cout << " | " << (double)row_sum[i]/n << endl;
    }
    for (int j=0; j<n; j++)
        cout << "--";
    cout << endl;
    for (int j=0; j<n; j++)
        cout << (double)col_sum[j]/n << " ";
    cout << endl;
    return 0;
}