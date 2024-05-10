#include <iostream>
using namespace std;

class MyPoint {
public:
    int x;
    int y;
    MyPoint() = default;
    MyPoint(int a, int b): x(a), y(b) {}
};

void someFunc1(MyPoint s) {
    MyPoint p(1, 2);
}

MyPoint *someFunc2(MyPoint s) {
    MyPoint *ptr = new MyPoint(3, 4);
    return ptr;
}

void someFunc3() {
    MyPoint *ptr = new MyPoint(5, 6);
    delete ptr;
}

int main() {
    MyPoint a(0, 0);
    someFunc1(a);
    MyPoint *r2 = someFunc2(a);
    someFunc3();
}

