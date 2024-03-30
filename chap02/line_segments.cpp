
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class MyPoint {
public:
    int x, y;
    MyPoint() = default;
    MyPoint(int a, int b): x(a), y(b) {}
};

class LineSegment {
public:
    MyPoint s, t;
    LineSegment() = default;
    LineSegment(MyPoint a, MyPoint b): s(a), t(b) {}
    LineSegment(int x1, int y1, int x2, int y2):
                    s(x1, y1), t(x2, y2) {}

    bool is_horizontal() {
        return s.x == t.x;
    }

    bool intersect(LineSegment other) {
        if (is_horizontal()) {
            return s.y<other.s.y && t.y>other.s.y &&
                    other.s.x<s.x && other.t.x>s.x;
        }
        else {
            return other.s.y<s.y && other.t.y>s.y &&
                   s.x<other.s.x && t.x>other.s.x;
        }
    }

    // Assume that two line segments intersect.
    MyPoint intersection_point(LineSegment other) {
        if (is_horizontal())
            return MyPoint(s.x, other.s.y);
        else
            return MyPoint(other.s.x, s.y);
    }
};

class MyRectangle {
public:
    MyPoint lu, rl;
    MyRectangle() = default;
    MyRectangle(MyPoint a, MyPoint b): lu(a), rl(b) {}
    MyRectangle(int x1, int y1, int x2, int y2): lu(x1, y1), rl(x2, y2) {}

    int area() {
        return (rl.x-lu.x)*(rl.y-lu.y);
    }

    bool intersect(LineSegment seg) {
        if (seg.is_horizontal()) {
            LineSegment left(lu, MyPoint(rl.x, lu.y));
            LineSegment right(MyPoint(lu.x, rl.y), rl);
            return seg.intersect(left) || seg.intersect(right);
        }
        else {
            LineSegment upper(lu, MyPoint(lu.x, rl.y));
            LineSegment lower(MyPoint(rl.x, lu.y), rl);
            return seg.intersect(upper) || seg.intersect(lower);
        }
    }
};

void get_inputs(istream &infile, vector<LineSegment> &hlines, vector<LineSegment> &vlines) {
    int x1, y1, x2, y2;
    while(infile >> x1 >> y1 >> x2 >> y2) {
        LineSegment s(x1, y1, x2, y2);
        if (s.is_horizontal())
            hlines.push_back(s);
        else
            vlines.push_back(s);
    }
}

void sort_by_x(vector<LineSegment> &hlines){
    for (int i=hlines.size()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (hlines.at(j).s.x > hlines.at(j+1).s.x)
                swap(hlines.at(j), hlines.at(j+1));
        }
    }
}

void sort_by_y(vector<LineSegment> &vlines){
    for (int i=vlines.size()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (vlines.at(j).s.y > vlines.at(j+1).s.y)
                swap(vlines.at(j), vlines.at(j+1));
        }
    }
}

bool intruding(MyRectangle r, vector<LineSegment> &hlines, vector<LineSegment> &vlines) {
    for (LineSegment s: hlines) {
        if (r.intersect(s))
            return true;
    }
    for (LineSegment s: vlines) {
        if (r.intersect(s))
            return true;
    }
    return false;
}

int main() {
    vector<LineSegment> hlines;
    vector<LineSegment> vlines;
    ifstream infile("line_segments.txt");
    get_inputs(infile, hlines, vlines);
    infile.close();

//    for (LineSegment seg: hlines)
//        cout << seg.s.x << " " << seg.s.y << " " << seg.t.x << " " << seg.t.y << endl;
//
//    for (LineSegment seg: vlines)
//        cout << seg.s.x << " " << seg.s.y << " " << seg.t.x << " " << seg.t.y << endl;

    sort_by_x(hlines);
    sort_by_y(vlines);

    int max_area = 0;
    int count = 0;
    for (int h1=0; h1<hlines.size()-1; h1++) {
        for (int h2=h1+1; h2<hlines.size(); h2++) {
            for (int v1=0; v1<vlines.size()-1; v1++) {
                for (int v2 = v1 + 1; v2 < vlines.size(); v2++) {
                    // (h1, h2, v1, v2)
                    if (hlines[h1].intersect(vlines[v1]) &&
                            hlines[h1].intersect(vlines[v2]) &&
                            hlines[h2].intersect(vlines[v1]) &&
                            hlines[h2].intersect(vlines[v2])) {
                        MyRectangle r(hlines[h1].intersection_point(vlines[v1]),
                                      hlines[h2].intersection_point(vlines[v2]));
                        bool intruded = intruding(r, hlines, vlines);
                        if (!intruded) {
                            count++;
                            if (r.area() > max_area)
                                max_area = r.area();
                        }
                    }
                }
            }
        }
    }
    cout << max_area << " " << count << endl;
    return 0;
}
