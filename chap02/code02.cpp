#include <iostream>
#include <string>
using namespace std;

class SalesData {
public:
    string isbn;
    int units_sold = 0;
    double revenue = 0.0;
};

SalesData combine(SalesData &x, SalesData &y);

int main() {
    SalesData p;
    p.isbn = "978-0-321-71411-4";
    p.units_sold = 3;
    p.revenue = 32000;

    cout << "p: " << p.isbn << " " << p.units_sold << " " << p.revenue << endl;

    SalesData q;
    q = p;      // b의 멤버들은 a의 멤버들과 동일한 값을 가진다.
    q.isbn = "112-0-321-76318-4";  // 물론 복사한 이후에는 따로 수정할 수 있다.

    cout << "q: " << q.isbn << " " << q.units_sold << " " << q.revenue << endl;

    SalesData arr[10];
    arr[0] = q; // arr[0]의 멤버들은 b의 멤버들과 동일한 값을 가진다.
    cout << "arr[0]: " << arr[0].isbn << " " << arr[0].units_sold << " " << arr[0].revenue << endl;

    SalesData r(p);
    cout << "r: " << r.isbn << " " << r.units_sold << " " << r.revenue << endl;

    SalesData s{r};
    cout << "s: " << s.isbn << " " << s.units_sold << " " << s.revenue << endl;

    SalesData t = {r};
    cout << "t: " << t.isbn << " " << t.units_sold << " " << t.revenue << endl;

    SalesData a, b, c;
    a.isbn = "978-0-321-71411-4";
    a.units_sold = 3;
    a.revenue = 32000;

    b.isbn = "978-0-321-71411-4";
    b.units_sold = 2;
    b.revenue = 25000;

    if (a.isbn == b.isbn) {
        c = combine(a, b);
        cout << "c: " << c.isbn << " " << c.units_sold << " " << c.revenue << endl;
    }

    return 0;
}

SalesData combine(SalesData &x, SalesData &y) {
    SalesData z;
    z.isbn = x.isbn;
    z.units_sold = x.units_sold + y.units_sold;
    z.revenue = x.revenue + y.revenue;
    return z;
}
