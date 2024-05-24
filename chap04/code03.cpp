#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructing base\n";
    }
};

class Derived: public Base {
public:
    Derived()  {
        cout << "Constructing derived\n";
    }
};

int main()  {
    Base b;
    Derived d;
    return 0;
}