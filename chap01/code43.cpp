#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec{10, 8, 1, 5, 4, 6, 11, 2};
    vector<int>::iterator it=vec.begin();
    while(it!=vec.end()) {
        if (*it % 2 == 0) {
            *it *= 2;
            it++;
        }
        else
            it = vec.erase(it);
    }

    for (auto it=vec.begin(); it!=vec.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}