#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int count = 0;
    for (int i=2; i<=N; i++)  {
        for (int j=2; j<=i/2; j++)  {
            if (i%j==0)
                count++;
        }
    }
    cout << count << endl;
    return 0;
}