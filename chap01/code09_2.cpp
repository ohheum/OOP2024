#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int tmp;
    cin >> tmp;
    while(tmp != -1) {
        if (tmp%2==1)
            sum += tmp;
        cin >> tmp;
    }
    cout << "The sum is " << sum << endl;
    return 0;
}