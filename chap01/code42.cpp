#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    for (int i=0; i<4; i++)
        v.push_back(i+1);

    vector<int>::iterator it;
    it = v.begin();

    // iterator의 증가
    it++;

    // iterator를 이용한 원소 읽기/쓰기
    int n = *it;
    cout << n << endl;
    *it = n*2;
    for (auto x: v)
        cout << x << " ";
    cout << endl;

    // 원소 삽입
    v.insert(it, 100);
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl; // it는 invalid해짐

    it = v.begin();
    it += 2;
    it = v.insert(it, 200);
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl; // it는 새로 insert된 원소의 위치를 가리킴

    // 원소 삭제
    it = v.begin();
    it += 3;
    it = v.erase(it);
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl; // it는 erase된 원소의 다음 위치를 가리킴

    return 0;
}
