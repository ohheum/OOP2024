#include <iostream>
using namespace std;

int main() {
    int sum = 0, count = 0;
    int tmp;
    while(true) {
        cin >> tmp;
        count++;
        sum += tmp;
        if (sum <= 0) {
            cout << "The count is " << count << endl;
            break;
        }
    }
    return 0;
}