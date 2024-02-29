#include <iostream>
#include <vector>
using namespace std;
double calculate_average(vector<int> &w);

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    double avg = calculate_average(v);
    cout << avg << endl;
    return 0;
}

double calculate_average(vector<int> &w) {
    double sum = 0.0;
    for (auto e : w)
        sum += e;
    return sum/w.size();
}