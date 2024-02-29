#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> data{1, 2, 3, 4};

    int sum = 0;
    for (auto t: data) {
        sum += t;
    }
    cout << sum << endl;


    int arr[10];
    arr[0] = 1, arr[1] = 2, arr[3] = 3;

    int sum_arr = 0;
    for (int t: arr) {   // 벡터 data에 저장된 각각의 정수 t에 대하여
        sum_arr += t;
    }
    cout << sum_arr << endl;

    return 0;
}
