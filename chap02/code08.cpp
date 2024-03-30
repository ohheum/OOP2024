#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MyPoint {
public:
    double x;
    double y;
    MyPoint(double a, double b): x(a), y(b) {}
};

class MyRectangle {
public:
    MyPoint lu;
    double width, height;

    MyRectangle(MyPoint p, double w, double h): lu(p), width(w), height(h) {}
    MyRectangle(double x, double y, double w, double h): lu(x, y), width(w), height(h) {}

    bool contains(MyPoint p) {
        return p.x >= lu.x && p.x <= lu.x+height && p.y >= lu.y
               && p.y <= lu.y + width;
    }

    double area() {
        return width*height;
    }
};

int main() {
    vector<MyRectangle> rects;
    ifstream infile("rects.txt");
    double x, y, w, h;
    while(infile >> x >> y >> w >> h) {  // eof()
        MyRectangle r(x, y, w, h);
        rects.push_back(r);
    }
    infile.close();

    cin >> x >> y;
    MyPoint p(x, y);
    for (auto r: rects) {
        if (r.contains(p))
            cout << r.lu.x << " " << r.lu.y << " " << r.width << " " << r.height << endl;
    }
    return 0;
}
