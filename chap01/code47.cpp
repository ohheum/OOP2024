#include <iostream>
using namespace std;

bool isPrime(int k);

int main() {
    for ( int i=2; i<=100000; i++ )   {
        if (isPrime(i))
            cout << i << endl;
    }
    return 0;
}

bool isPrime(int k) {
    if (k<2)
        return false;
    for (int i=2; i*i<=k; i++)  {
        if (k%i==0)
            return false;
    }
    return true;
}