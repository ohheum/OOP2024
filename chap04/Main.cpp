#include "EventScheduler.h"

void process_command(EventScheduler scheduler) {
    string command, event_type, date_string, content, keyword;
    while(1) {
        cout << "$ ";
        cin >> command;
        if (command == "add") {
            cin >> event_type;
            cin >> date_string;
            getline(cin, content);
            scheduler.add_event(event_type, date_string, content);
        }
        else if (command == "find") {
            try {
                cin >> date_string;
                Date d(date_string);
                scheduler.show_relevant_events(d);
            }
            catch (std::invalid_argument const& ex)
            {
                cout << "Invalid Date String!!" << ex.what() << '\n';
            }
        }
        else if (command == "search") {
            getline(cin, keyword);
            scheduler.search_events(keyword);
        }
        else if (command == "list") {
            scheduler.show_all_events();
        }
        else if (command == "delete") {
            int id;
            cin >> id;
            scheduler.delete_event(id);
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
