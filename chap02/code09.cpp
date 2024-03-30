#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MyPoint {
public:
    double x;
    double y;

//    MyPoint(double a, double b): x(a), y(b) {}
};

class MyRectangle {
public:
    MyPoint lu;
    double width, height;

//    MyRectangle(MyPoint p, double w, double h): lu(p), width(w), height(h) {}
//    MyRectangle(double x, double y, double w, double h): lu(x, y), width(w), height(h) {}

    bool contains(MyPoint p) {
        return p.x >= lu.x && p.x <= lu.x+height && p.y >= lu.y && p.y <= lu.y + width;
    }
};

int main() {
    MyRectangle r;
}
