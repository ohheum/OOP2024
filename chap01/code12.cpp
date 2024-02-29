
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int p=1;
    while (p*2<=N)
        p *= 2;

    cout << "The answer is " << p << endl;
    return 0;
}