#include <iostream>
#include <vector>
using namespace std;

class MyPoint {
public:
    double x, y;
    MyPoint() = default;
    MyPoint(double a, double b): x(a), y(b) {}
};

class MyRectangle {
private:
    MyPoint *lu;
    double width, height;
public:
    MyRectangle() = default;
    MyRectangle(MyPoint *p, double w, double h): lu(p), width(w), height(h) {}
    MyRectangle(double x, double y, double w, double h): lu( new MyPoint(x, y)), width(w), height(h) {}
    double xmin() {
        return lu->x;
    }
    double xmax() {
        return lu->x+height;
    }
    double ymin() {
        return lu->y;
    }
    double ymax() {
        return lu->y+width;
    }
};

int main() {
    vector<MyRectangle *> rects;
    int n;
    double x, y, w, h;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x >> y >> w >> h;
        MyRectangle *r = new MyRectangle(x, y, w, h);
        rects.push_back(r);
    }
    double min_x = rects.at(0)->xmin();
    double max_x = rects.at(0)->xmax();
    double min_y = rects.at(0)->ymin();
    double max_y = rects.at(0)->ymax();

    for (auto r: rects) {
        if (r->xmin() < min_x) min_x = r->xmin();
        if (r->xmax() > max_x) max_x = r->xmax();
        if (r->ymin() < min_y) min_y = r->ymin();
        if (r->ymax() > max_y) max_y = r->ymax();
    }
    cout << min_x << " " << min_y << " " << max_y-min_y << " " << max_x-min_x << endl;
}