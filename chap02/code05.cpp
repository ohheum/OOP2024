#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class MyPoint {
public:
    double x;
    double y;
};

class MyRectangle {
public:
    MyPoint lu;
    double width;
    double height;
};

void bubbleSort(vector<MyRectangle> &rects);

int main() {
    vector<MyRectangle> rects;
    ifstream source("rects.txt");
    double x, y, w, h;
    while (source >> x >> y >> w >> h) {
        MyRectangle tmp;
        tmp.lu.x = x, tmp.lu.y = y, tmp.height = h, tmp.width = w;
        rects.push_back(tmp);
    }
    source.close();
    bubbleSort(rects);
    for (auto r: rects) {
        cout << r.lu.x << " " << r.lu.y << " " << r.width << " " << r.height << endl;
    }
}

void bubbleSort(vector<MyRectangle> &rects)
{
    for (int i=rects.size()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (rects[j].width*rects[j].height > rects[j+1].width*rects[j+1].height)
                swap(rects[j], rects[j+1]);
        }
    }
}