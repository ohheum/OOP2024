#include <iostream>
using namespace std;
int main() {
    cout << sizeof(int) << " " << sizeof(int *) << endl;
    cout << sizeof(char) << " " << sizeof(char *) << endl;
    cout << sizeof(double) << " " << sizeof(double *) << endl;

    int c = 12;
    int *p;
    p = &c;

    cout << p << endl;
    cout << *p << endl;

    *p = 20;
    cout << *p << endl;

    int *pt1, *pt2;
    int x=3, y=2;

    // 초기화되지 않은 포인터
//    x = *pt1;		// wrong
//    *pt1 = 12;		// wrong

    // 포인터 간의 치환
    pt1 = &x;
    pt2 = pt1;
    y = *pt2;

    return 0;
}