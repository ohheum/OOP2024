#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SalesData {
public:
    string isbn;
    int units_sold = 0;
    double revenue = 0.0;
};

vector<string> split_line(string &line, char delimiter);
SalesData parse_line(string &line);
void insertRecord(SalesData r, vector<SalesData> &records);
void sort_by_average_price(vector<SalesData> &records);

int main() {
    vector<SalesData> records;
    ifstream infile("sales_records.csv");
    string line;
    while(getline(infile, line)) {
        if (line.length() <= 0)
            continue;
        SalesData r = parse_line(line);
        insertRecord(r, records);
    }
    cout << endl;
    infile.close();

    sort_by_average_price(records);
    for (auto r: records)
        cout << r.isbn << ":" << r.units_sold << ":" << r.revenue << ":" << r.revenue/r.units_sold << endl;

    return 0;
}

SalesData parse_line(string &line) {
    SalesData r;
    vector<string> tokens = split_line(line,  ',');
    r.isbn = tokens[0];
    r.units_sold = stoi(tokens[1]);
    r.revenue = stod(tokens[2]);
    return r;
}

vector<string> split_line(string &line, char delimiter) {
    vector<string> tokens;
    stringstream sstream(line);
    string str;
    while(getline(sstream, str, delimiter))
        tokens.push_back(str);
    return tokens;
}

//SalesData parse_line2(string &line) {
//    SalesData r;
//    int start = 0;
//    int end = line.find(',');
//    r.isbn = line.substr(0, end-start);
//
//    start = end+1;
//    end = line.find(',', start);
//    r.units_sold = stoi(line.substr(start, end-start));
//
//    start = end+1;
//    end = line.find(',', start);
//    r.revenue = stod(line.substr(start, end-start));
//    return r;
//}

void insertRecord(SalesData r, vector<SalesData> &records) {
    for (auto it=records.begin(); it!=records.end(); it++) {
        if ((*it).isbn == r.isbn) {
            it->units_sold += r.units_sold;
            it->revenue += r.revenue;
            return;
        }
    }
    records.push_back(r);
}

//void insertRecord(SalesData r, vector<SalesData> &records) {
//    for (auto it=records.begin(); it!=records.end(); it++) {
//        if ((*it).isbn == r.isbn) {
//            it->units_sold += r.units_sold;
//            it->revenue += r.revenue;
//            return;
//        }
//    }
//    records.push_back(r);
//}

//void insertRecord(SalesData r, vector<SalesData> &records) {
//    for (SalesData d: records) {
//        if (d.isbn == r.isbn) {
//            d.units_sold += r.units_sold;
//            d.revenue += r.revenue;
//            return;
//        }
//    }
//    records.push_back(r);
//}

void sort_by_average_price(vector<SalesData> &records)  {
    for (int i=records.size()-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (records[j].revenue/records[j].units_sold < records[j+1].revenue/records[j+1].units_sold)  {
//                SalesData tmp = records[j];
//                records[j] = records[j+1];
//                records[j+1] = tmp;
                swap(records[j], records[j+1]);
            }
        }
    }
}
