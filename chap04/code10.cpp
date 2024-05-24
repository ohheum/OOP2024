#include <iostream>
using namespace std;

class Base {
    int x;
public:
    Base()  { cout << "Constructing base\n"; }
    virtual ~Base()  { cout << "Destructing base\n"; }
};

class Derived: public Base {
    int y;
public:
    Derived() 	{ cout << "Constructing derived\n"; }
   ~Derived()	{ cout << "Destructing derived\n"; }
};

int main() {
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    return 0;
}