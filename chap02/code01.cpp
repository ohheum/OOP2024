#include <iostream>
#include <string>
using namespace std;

class SalesData {
public:
    string isbn;
    int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    SalesData first;
    first.isbn = "978-0-321-71411-4";
    first.units_sold = 3;
    first.revenue = 32000;
    cout << first.isbn << " " <<  first.units_sold << " " << first.revenue
         << endl;

    SalesData data[10];
    data[0] = first;
    data[1].isbn = "978-0-111-71524-1";
    data[1].units_sold = 11;
    data[1].revenue = 56000;

    cout << data[1].isbn << " " << data[1].units_sold << " " <<
         data[1].revenue << endl;
    return 0;
}