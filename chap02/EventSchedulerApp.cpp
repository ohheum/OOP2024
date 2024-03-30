#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Date {
private:
    int year, month, day;

public:
    Date() = default;
    Date(int y, int m, int d): year(y), month(m), day(d) {}
    Date(string date_string) {
        int start = 0, end = 0;
        while (date_string.at(end) != '/') end++;
        year = stoi(date_string.substr(start, end));

        end++, start = end;
        while (date_string.at(end) != '/') end++;
        month = stoi(date_string.substr(start, end-start));

        start = end + 1;
        day = stoi(date_string.substr(start));
    }

    bool operator<(Date &rhs) {
        return year<rhs.year || (year==rhs.year && month<rhs.month) ||
               (year==rhs.year && month==rhs.month && day<rhs.day);
    }

    bool operator>(Date &rhs) {
        return year>rhs.year || (year==rhs.year && month>rhs.month) ||
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

    void print(ostream &out) {
        out << year << "/" << month << "/" << day;
    }
};

class OneDayEvent {
private:
    Date date;
    string content;
public:
    OneDayEvent() = default;
    OneDayEvent(Date d, string str): date(d), content(str) {}

    bool relevant_to(Date &theDay) {
        return theDay == date;
    }

    void print(ostream &out) {
        date.print(out);
        out << ":" << content;
    }
};

class PeriodEvent {
private:
    Date begin, end;
    string content;
public:
    PeriodEvent() = default;
    PeriodEvent(Date d1, Date d2, string str): begin(d1), end(d2), content(str) {}

    bool relevant_to(Date &theDay) {
        return begin <= theDay && theDay <= end;
    }

    void print(ostream &out) {
        begin.print(out);
        out << "-";
        end.print(out);
        out << ":" << content;
    }
};

class DeadlineEvent {
private:
    Date deadline;
    string content;
public:
    DeadlineEvent() = default;
    DeadlineEvent(Date d, string str): deadline(d), content(str) {}

    bool relevant_to(Date &theDay) {
        return theDay <= deadline;
    }

    void print(ostream &out) {
        out << "~";
        deadline.print(out);
        out << ":" << content;
    }
};

class EventScheduler {
private:
    vector<OneDayEvent> oneday_events;
    vector<PeriodEvent> period_events;
    vector<DeadlineEvent> deadline_events;

    void parse_period_string(string period_str, Date &s, Date &t) {
        int idx = period_str.find_first_of("-");
        Date d1(period_str.substr(0, idx));
        Date d2(period_str.substr(idx+1));
        s = d1, t = d2;
    }

public:
    void add_oneday_event(string date_string, string content);
    void add_period_event(string date_string, string content);
    void add_deadline_event(string date_string, string content);
    void show_relevant_events(Date theDay);
    void show_all_events();
    void load_data_file(string file_name);
};

void EventScheduler::add_oneday_event(string date_string, string content) {
    Date d(date_string);
    OneDayEvent e(d, content);
    oneday_events.push_back(e);
}

void EventScheduler::add_period_event(string date_string, string content) {
    Date s, t;
    parse_period_string(date_string, s, t);
    PeriodEvent e(s, t, content);
    period_events.push_back(e);
}

void EventScheduler::add_deadline_event(string date_string, string content) {
    Date d(date_string);   // excluding leading ~
    DeadlineEvent e(d, content);
    deadline_events.push_back(e);
}

void EventScheduler::show_relevant_events(Date theDay) {
    for (auto ev: oneday_events) {
        if (ev.relevant_to(theDay)) {
            ev.print(cout);
            cout << endl;
        }
    }
    for (auto ev: period_events) {
        if (ev.relevant_to(theDay)) {
            ev.print(cout);
            cout << endl;
        }
    }
    for (auto ev: deadline_events) {
        if (ev.relevant_to(theDay)) {
            ev.print(cout);
            cout << endl;
        }
    }
}

void EventScheduler::show_all_events() {
    for (auto ev: oneday_events) {
        ev.print(cout);
        cout << endl;
    }
    for (auto ev: period_events) {
        ev.print(cout);
        cout << endl;
    }
    for (auto ev: deadline_events) {
        ev.print(cout);
        cout << endl;
    }
}

void EventScheduler::load_data_file(string file_name) {
    ifstream infile(file_name);
    string line, date_string, content;
    while(getline(infile, line)) {
        stringstream sstream(line);
        sstream >> date_string;
        getline(sstream, content);
        if (date_string.find('-') != string::npos)   // period event
            add_period_event(date_string, content);
        else if (date_string.find('~') != string::npos)   // deadline event
            add_deadline_event(date_string.substr(1), content);
        else      // one day event
            add_oneday_event(date_string, content);
    }
    infile.close();
}

void process_command(EventScheduler scheduler) {
    string command, event_type, date_string, content;
    while(1) {
        cout << "$ ";
        cin >> command;
        if (command == "add") {
            cin >> event_type;
            cin >> date_string;
            getline(cin, content);

            if (event_type == "-O")   // one day event
                scheduler.add_oneday_event(date_string, content);
            else if (event_type == "-P")   // period event
                scheduler.add_period_event(date_string, content);
            else if (event_type == "-D")  // deadlined event
                scheduler.add_deadline_event(date_string, content);
            else  // unsupported event type
                cout << "Unsupported event type." << endl;
        }
        else if (command == "find") {
            cin >> date_string;
            Date d(date_string);
            scheduler.show_relevant_events(d);
        }
        else if (command == "list") {
            scheduler.show_all_events();
        }
        else if (command == "exit") {
            break;
        }
    }
}

int main() {
    EventScheduler scheduler;
    scheduler.load_data_file("events.txt");
    process_command(scheduler);

    return 0;
}

