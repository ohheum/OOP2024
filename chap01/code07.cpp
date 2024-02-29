#include <iostream>
using namespace std;

int main()  {
    int s, t;
    cin >> s >> t;
    int count1 = 0, count2 = 0, count3 = 0;

    for (int i=s; i<=t; i++)  {
        if (i%2==0)
            count1++;
        if (i%3==0)
            count2++;
        if (i%2!=0 && i%3!=0)
            count3++;
    }

    cout << "The results are " << count1 << ", " << count2 << ", and " <<
         count3 << endl;
    return 0;
}