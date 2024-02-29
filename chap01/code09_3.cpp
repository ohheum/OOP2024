#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int tmp;
    while(1) {
        cin >> tmp;
        if (tmp == -1)
            break;
        if (tmp%2==1)
            sum += tmp;
    }
    cout << "The sum is " << sum << endl;
    return 0;
}