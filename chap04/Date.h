#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year, month, day;

public:
    Date();
    Date(int y, int m, int d);
    Date(string date_string);

    bool operator<(Date &rhs);
    bool operator>(Date &rhs);
    bool operator==(Date &rhs);
    bool operator!=(Date &rhs);
    bool operator<=(Date &rhs);
    bool operator>=(Date &rhs);
    void print(ostream &out);
};
