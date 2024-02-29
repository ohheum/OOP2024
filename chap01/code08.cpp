#include <iostream>
using namespace std;

int main() {
    int count_odd = 0, sum = 0;
    int tmp;
    while(count_odd<10) {
        cin >> tmp;
        if (tmp%2==1) {
            sum += tmp;
            count_odd++;
        }
    }
    cout << "The sum is " << sum << endl;
    return 0;
}