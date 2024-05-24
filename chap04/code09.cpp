#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point() = default;
    Point(double a, double b): x(a), y(b) {}
    double dist(Point p) {
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }
};

class Shape {
private:
    string shape_type;
public:
    Shape() = default;
    Shape(string type): shape_type(type) {}
    string get_type() {
        return shape_type;
    }

    virtual double area() = 0;

    virtual double minx() = 0;
    virtual double maxx() = 0;
    virtual double miny() = 0;
    virtual double maxy() = 0;

    virtual void print(ostream &out) {
        out << shape_type;
    }
};



class Rect: public Shape {
protected:
    Point lu, rl;
public:
    Rect() = default;
    Rect(Point a, Point b): Shape("rectangle"), lu(a), rl(b) {}
    Rect(double x1, double y1, double x2, double y2):
            Shape("rectangle"), lu(Point(x1, y1)), rl(Point(x2, y2)) {}
    Rect(istream &in): Shape("rectangle") {
        in >> lu.x >> lu.y >> rl.x >> rl.y;
    }

    double area() override {
        return (rl.x-lu.x)*(rl.y-lu.y);
    }

    double minx() override {
        return lu.x;
    }

    double maxx() {
        return rl.x;
    }

    double miny() {
        return lu.y;
    }

    double maxy() {
        return rl.y;
    }

    void print(ostream &out) override {
        Shape::print(out);
        out << ": " << lu.x << " " << lu.y << " " << rl.x << " " << rl.y;
    }
};

class Circle: public Shape {
private:
    Point center;
    double radius;
public:
    Circle() = default;
    Circle(Point a, double r): Shape("circle"), center(a), radius(r) {}
    Circle(double x, double y, double r):
            Shape("circle"), center(Point(x, y)), radius(r) {}
    Circle(istream &in): Shape("circle") {
        in >> center.x >> center.y >> radius;
    }

    double area() {
        return M_PI*radius*radius ;
    }

    double minx() {
        return center.x-radius;
    }

    double maxx() {
        return center.x+radius;
    }

    double miny() {
        return center.y-radius;
    }

    double maxy() {
        return center.y+radius;
    }

    void print(ostream &out) override {
        Shape::print(out);
        out << ": " << center.x << " " << center.y << " " <<radius;
    }
};

int main() {
    vector<Shape *> vec;
    string stype;

    while(true) {
        cin >> stype;
        if (stype=="R") {
            Rect *r = new Rect(cin);
            vec.push_back(r);
        }
        else if (stype=="C") {
            Circle *c = new Circle(cin);
            vec.push_back(c);
        }
        else if (stype=="exit")
            break;
    }

    for (Shape *s: vec) {
        s->print(cout);
        cout << endl;
    }

    double max_area = 0;
    for (auto &s: vec) {
        if (s->area() > max_area)
            max_area = s->area();
    }
    cout << max_area << endl;

    double min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX,
            max_y = INT_MIN;
    for (auto &c: vec) {
        if (c->minx() < min_x) min_x = c->minx();
        if (c->maxx() > max_x) max_x = c->maxx();
        if (c->miny() < min_y) min_y = c->miny();
        if (c->maxy() > max_y) max_y = c->maxy();
    }

    cout << min_x << " " << max_x << " " << min_y << " " << max_y << endl;

    return 0;
}