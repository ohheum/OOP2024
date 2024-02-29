#include <iostream>
using namespace std;

void test_vec(vector<int> v);
void test_arr(int arr[]);

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Before:\n";
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    for (int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl;

    test_vec(v);
    test_arr(arr);

    cout << "After:\n";
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    for (int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

void test_vec(vector<int> v)
{
    v[0] = 0, v[1] = 1;
    cout << "Within:\n";
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

void test_arr(int arr[])
{
    arr[0] = 0, arr[1] = 1;
    cout << "Within:\n";
    for (int i=0; i<5; i++)
        cout << arr[i] << " ";
    cout << endl;
}