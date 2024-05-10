#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Foo {
public:
    int val;
    Foo() = default;
    Foo(int a): val(a) {}
    ~Foo() {
        cout << "Foo class destructor executed." << endl;
    }
};

class Bar {
public:
    Foo *ptr;
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
    ~Bar() {
        clearMembers();
        cout << "Bar class destructor executed." << endl;
    }

private:
    void clearMembers() {
        delete ptr;
        for (auto p: vec)
            delete p;
        vec.clear();
    }
};

void func() {
    Foo *f = new Foo(100);
    vector<Foo *> v{new Foo(1), new Foo(2), new Foo(3)};
    Bar a(f, v);
}

int main() {
    func();
    return 0;
}


