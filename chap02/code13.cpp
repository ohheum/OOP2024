#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Date {
private:
    int year, month, day;
    vector<int> short_months{4, 6, 9, 11};
    bool is_short_month() {
        return find(short_months.begin(), short_months.end(), month) != short_months.end();
    }

    bool last_day_of_month() {
        return month == 2 && day == 28 || is_short_month() && day==30 || day==31;
    }

    bool last_day_of_year() {
        return month == 12 && day == 31;
    }

public:
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}

    bool operator<(Date &rhs) {
        return year<rhs.year ||
                (year==rhs.year && month<rhs.month) ||
                (year==rhs.year && month==rhs.month && day<rhs.day);
    }

    bool operator>(Date &rhs) {
        return year>rhs.year ||
               (year==rhs.year && month>rhs.month) ||
               (year==rhs.year && month==rhs.month && day>rhs.day);
    }

    bool operator==(Date &rhs) {
        return year==rhs.year && month==rhs.month && day==rhs.day;
    }

    bool operator!=(Date &rhs) {
        return !(*this == rhs);
    }

    bool operator<=(Date &rhs) {
        return *this<rhs || *this==rhs;
    }

    bool operator>=(Date &rhs) {
        return *this>rhs || *this==rhs;
    }

    Date operator++() {   // prefix increment operator
        if (last_day_of_year()) {
            year++, month=1, day=1;
        }
        else if (last_day_of_month()) {
            month++; day=1;
        }
        else {
            day++;
        }
        return *this;
    }

    Date operator++(int) {   // postfix increment operator
        Date ret = *this;
        if (last_day_of_year()) {
            year++, month=1, day=1;
        }
        else if (last_day_of_month()) {
            month++; day=1;
        }
        else {
            day++;
        }
        return ret;
    }

    int operator-(Date &rhs) {

        if (*this == rhs)
            return 0;
        else if (*this < rhs) {
            Date temp = *this;
            int diff = 0;
            while(temp < rhs) {
                temp++;
                diff++;
            }
            return -diff;
        }
        else {
            Date rhs_temp = rhs;
            int diff = 0;
            while(*this > rhs_temp) {
                rhs_temp++;
                diff++;
            }
            return diff;
        }
    }

    Date operator+(int k) {
        Date temp = *this;
        for (int i=0; i<k; i++)
            ++temp;
        return temp;
    }

    void print(ostream &out) {
        out << year << "/" << month << "/" << day;
    }
};

void sort_dates(vector<Date> &dates) {
    for (int i=dates.size()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (dates.at(j) > dates.at(j+1))
                swap(dates.at(j), dates.at(j+1));
        }
    }
}

int main() {
    vector<Date> dates;
    ifstream infile("dates.txt");
    int y, m, d;
    while(infile >> y >> m >> d) {
        dates.push_back(Date(y, m, d));
    }
    infile.close();

    sort_dates(dates);
    for (Date &d: dates) {
        d.print(cout);
        cout << endl;
    }

    cin >> y >> m >> d;
    Date theDay(y, m, d);

    int min_diff = abs(dates[0] - theDay);
    Date closest_day = dates[0];
    for (Date &dt : dates) {
        int diff = abs(dt-theDay);
        if (diff < min_diff) {
            min_diff = diff;
            closest_day = dt;
        }
    }
    closest_day.print(cout);
    cout << " with difference " << min_diff << " days." << endl;

    return 0;
}


