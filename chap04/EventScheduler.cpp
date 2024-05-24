#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "EventScheduler.h"

using namespace std;

void EventScheduler::parse_period_string(string period_str, Date &s, Date &t) {
    int idx = period_str.find_first_of("-");
    Date d1(period_str.substr(0, idx));
    Date d2(period_str.substr(idx+1));
    s = d1, t = d2;
}

void EventScheduler::add_event(string event_type, string date_string, string content) {
    try {
        if (event_type == "-O")   // one day event
            add_oneday_event(date_string, content);
        else if (event_type == "-P")   // period event
            add_period_event(date_string, content);
        else if (event_type == "-D")  // deadlined event
            add_deadline_event(date_string, content);
    }
    catch (std::invalid_argument const& ex)
    {
        cout << "Invalid Date String!!" << ex.what() << '\n';
    }
}

void EventScheduler::add_oneday_event(string date_string, string content) {
    Date d(date_string);
    OneDayEvent *e = new OneDayEvent(d, content);
    events.push_back(e);
}

void EventScheduler::add_period_event(string date_string, string content) {
    Date s, t;
    parse_period_string(date_string, s, t);
    PeriodEvent *e = new PeriodEvent(s, t, content);
    events.push_back(e);
}

void EventScheduler::add_deadline_event(string date_string, string content) {
    Date d(date_string);   // excluding leading ~
    DeadlineEvent *e = new DeadlineEvent(d, content);
    events.push_back(e);
}

void EventScheduler::show_relevant_events(Date theDay) {
    for (auto ev: events) {
        if (ev->relevant_to(theDay)) {
            ev->print(cout);
            cout << endl;
        }
    }
}

void EventScheduler::search_events(string keyword) {
    for (auto it=events.begin(); it!=events.end(); it++) {
        if ((*it)->contains(keyword)) {
            (*it)->print(cout);
            cout << endl;
        }
    }
}

void EventScheduler::show_all_events() {
    for (auto ev: events) {
        ev->print(cout);
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

void EventScheduler::delete_event(int id) {
    for (auto it=events.begin(); it!=events.end(); it++) {
        if ((*it)->get_id() == id) {
            delete *it;
            events.erase(it);
            return;
        }
    }
    cout << "No such event exists." << endl;
}


