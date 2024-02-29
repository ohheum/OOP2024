#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int v, sum = 0;

    for (int i=0; i<N; i++) {
        cin >> v;
        sum += v;  // sum = sum + v;
    }

    cout <<"The average is " << sum/(double)N << endl;  // type casting

    return 0;
}