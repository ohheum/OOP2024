#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class MyPoint {
public:
    double x = 0;
    double y = 0;

    MyPoint() = default;  // almost same as "MyPoint() {}"
    MyPoint(double a, double b): x(a), y(b) {}

    double dist2origin() {
        return sqrt(x*x + y*y);
    }
};

class MyRectangle {
public:
    MyPoint lu;
    double width, height;

    MyRectangle(MyPoint p, double w, double h): lu(p), width(w), height(h) {}
    MyRectangle(double x, double y, double w, double h): lu(x, y), width(w), height(h) {}

    bool contains(MyPoint p) {
        return p.x >= lu.x && p.x <= lu.x+height && p.y >= lu.y && p.y <= lu.y + width;
    }

    double area() {
        return width*height;
    }

    double dist_center2origin() {
        MyPoint center(lu.x + height/2.0, lu.y + width/2.0);
        return center.dist2origin();
    }

    void print(ostream &out) {
        out << lu.x << " " << lu.y << " " << width << " " << height;
    }
};

void read_input(istream &source, vector<MyRectangle> &rects) {
    double x, y, w, h;
    while(source >> x >> y >> w >> h)
        rects.push_back(MyRectangle(x, y, w, h));
}

void sort_by_dist(vector<MyRectangle> &rects) {
    for (int i=rects.size()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (rects[j].dist_center2origin() > rects[j+1].dist_center2origin())
                swap(rects[j], rects[j+1]);
        }
    }
}

int main() {
    vector<MyRectangle> rects;
    ifstream infile("rects.txt");
    read_input(infile, rects);
    infile.close();

    sort_by_dist(rects);

    for (MyRectangle r: rects) {
        r.print(cout);
        cout << ": " << r.dist_center2origin() << endl;
    }

    return 0;
}
