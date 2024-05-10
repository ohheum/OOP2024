#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Foo {
public:
    int val;
    Foo() = default;
    Foo(int a): val(a) {}
};

class Bar {
public:
    Foo *ptr = nullptr;
    vector<Foo *> vec;

    Bar() = default;

    Bar(const Bar &t) {
        ptr = new Foo(*t.ptr);
        for (auto &pt: t.vec)
            vec.push_back(new Foo(*pt));
    }

    Bar &operator=(const Bar &t) {
        ptr = new Foo(*t.ptr);
        for (auto &pt: t.vec)
            vec.push_back(new Foo(*pt));
        return *this;
    }
};

int main() {
    Bar a;
    a.ptr = new Foo(100);
    a.vec.push_back(new Foo(1));
    a.vec.push_back(new Foo(2));
    a.vec.push_back(new Foo(3));

    Bar c;
    c.ptr = new Foo(10);
    c.vec.push_back(new Foo(10));
    c.vec.push_back(new Foo(20));

    cout << a.ptr->val << " " << a.vec[0]->val << endl;
    cout << c.ptr->val << " " << c.vec[0]->val << endl;

    return 0;
}


