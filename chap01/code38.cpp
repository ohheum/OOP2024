#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data;
    int k;
    while(true) {
        cin >> k;
        if (k==-1) break;
        data.push_back(k);
    }

    int min = data[0], second_min = data[1];
    if (min > second_min) {
        min = data[1];
        second_min = data[0];
    }

    for (int i=2; i<data.size(); i++)  {
        if (data[i] < min) {
            second_min = min;
            min = data[i];
        }
        else if (data[i] < second_min ){
            second_min = data[i];
        }
    }

    cout << "The min is " << min << " and the second-min is " << second_min << endl;
    return 0;
}