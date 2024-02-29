#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int s = v.size();
    cout << s << endl;

    cout << v[0] << " " << v.at(1) << " " << v[2] << endl;
    v[1] = 4;
    v.at(2) = 5;

    cout << v[0] << " " << v.at(1) << " " << v[2] << endl;

    cout << v[3] << " " << v[4] << endl;  // it may work, but don't do this
    v[3] = 100;             // it may work, but don't do this

//    cout << v.at(4) << endl;    // error

    // vector initialization
    vector<int> v2 = {1, 2, 3, 4};
    vector<int> v3{1, 2, 3, 4};  // preferred way
//    vector<int> v4 = (3, 4);   // wrong
    vector<int> v5(3, 4);   // v5 contains 3 of 4s

    // vector can be copied
    vector<int> v6(v2);
    vector<int> v7{v2};
    vector<int> v8 = v2;

    cout << v2.size() << " " << v3.size() << " " << v5.size() << " "
                    << v6.size() << " " << v7.size() << " " << v8.size() << endl;

    v2[0] = 100;
    for (int a: v6)
        cout << a << " ";
    cout << endl;

    for (int a: v8)
        cout << a << " ";
    cout << endl;

    int arr[] = {1, 2, 3, 4};
    int arr2[4];
//    arr2 = arr;     // wrong, array can not be copied

    return 0;
}
