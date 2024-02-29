#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    for ( int x=0; x<=100; x++ )   {
        for ( int y=0; y<x; y++) {
            if (x*x + y*y <= 10000)
                count++;
        }
    }
    cout << "The number of points is " << count << endl;
    return 0;
}