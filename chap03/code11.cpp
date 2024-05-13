#include <iostream>
#include "code11.h"

class Foo;

class Bar {
public:
    Bar();
    Bar(Foo f);
    Foo *bar_func(int x);
};

int some_func();
int some_func2(Foo f);

int main() {
    Bar b;
    Foo *p_foo = b.bar_func(10);
    int result = some_func();
    return 0;
}