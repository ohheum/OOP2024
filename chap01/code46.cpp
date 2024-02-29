#include <iostream>
using namespace std;

int power(int n, int m);

int main() {
    int a, b;
    cin >> a >> b;
    int result = power(a, b);
    cout << result << endl;
    return 0;

}

int power(int x, int y) {
    int result = 1;
    for ( int i=0; i<y; i++ )
        result *= x;
    return result;
}