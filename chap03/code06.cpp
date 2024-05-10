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
    Foo *ptr;
    vector<Foo *> vec;
    Bar() = default;

    Bar(const Bar &t) {
        cout << "copy constr" << endl;
        ptr = new Foo(*t.ptr);
        for (auto &pt: t.vec)
            vec.push_back(new Foo(*pt));
    }
};

int main() {
    Bar a;
    a.ptr = new Foo(100);
    a.vec.push_back(new Foo(1));
    a.vec.push_back(new Foo(2));
    a.vec.push_back(new Foo(3));

    Bar b=a;
    a.ptr->val = 200;
    a.vec[0]->val = 300;

    cout << a.ptr->val << " " << a.vec[0]->val << endl;
    cout << b.ptr->val << " " << b.vec[0]->val << endl;

    return 0;
}


