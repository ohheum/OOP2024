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
    Bar(Foo *p, vector<Foo *> v) : ptr(p), vec(v) {}

    Bar(const Bar &t) {
        ptr = new Foo(*t.ptr);
        for (auto &pt: t.vec)
            vec.push_back(new Foo(*pt));
    }

    Bar &operator=(const Bar &t) {
        clearMembers();
        ptr = new Foo(*t.ptr);
        for (auto &pt: t.vec)
            vec.push_back(new Foo(*pt));
        return *this;
    }

private:
    void clearMembers() {
        delete ptr;
        for (auto p: vec)
            delete p;
        vec.clear();
    }
};

int main() {
    Foo *f = new Foo(100);
    vector<Foo *> v{new Foo(1),new Foo(2), new Foo(3)};
    vector<Foo *> w{new Foo(10),new Foo(20)};
    Bar a(f, v);
    Bar c(new Foo(200), w);

    c = a;

    for (Foo *ptr: c.vec)
        cout << ptr->val << ", ";
    cout << endl;

    return 0;
}


