#include <iostream>
using namespace std;

class MyPoint {
public:
    double x, y;
    MyPoint() = default;
    MyPoint(double a, double b): x(a), y(b) {}
};

class MyRectangle {
public:
    MyPoint lu;
    double width, height;
    MyRectangle(double x, double y, double w, double h):
            lu(x, y), width(w), height(h){}
    double area() {
        return width*height;
    }
};

int main() {
    MyRectangle r(0.0, 0.0, 2.0, 3.0);

    MyRectangle *pr = &r;

    cout << (*pr).lu.x << " " << pr->lu.y << " "
         << pr->width << " " << pr->height << endl;

    pr->lu.x = 1.0;
    pr->width = 4.0;
}