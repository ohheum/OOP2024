#include <iostream>
using namespace std;

int main() {
    int sum = 0, count = 0;
    int tmp;
    do {
        cin >> tmp;
        count++;
        sum += tmp;
    } while(sum > 0);
    cout << "The count is " << count << endl;
    return 0;
}