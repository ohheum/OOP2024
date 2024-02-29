#include <iostream>
using namespace std;

int main() {
    int sum = 0, count = 0;
    int tmp;
    cin >> tmp;
    sum += tmp;
    count++;
    while (sum > 0) {
        cin >> tmp;
        count++;
        sum += tmp;
    }
    cout << "The count is " << count << endl;
    return 0;
}