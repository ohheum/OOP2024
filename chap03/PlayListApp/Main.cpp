#include <iostream>
#include "MusicManager.h"
#include "Tools.h"

void process_command(MusicManager manager) {
    string command, filename, p_name, keyword;
    int song_id;
    while (true) {
        cout << "$ ";
        cin >> command;
        if (command == "load") {
            cin >> filename;
            manager.load(filename);
        } else if (command == "playlist") {
            manager.list_playlist();
        } else if (command == "show") {
            getline(cin, p_name);
            manager.show_plist(trim(p_name));
        } else if (command == "find") {
            getline(cin, keyword);
            manager.find_song(trim(keyword));
        } else if (command == "add") {
            manager.get_and_add_song();
        } else if (command == "delete") {
            cin >> song_id;
            manager.delete_song(song_id);
        } else if (command == "addtolist") {
            cin >> song_id;
            getline(cin, p_name);
            manager.add_to_list(song_id, trim(p_name));
        }
        else if (command == "deletefromlist") {
            cin >> song_id;
            getline(cin, p_name);
            manager.delete_from_list(song_id, trim(p_name));
        }
        else if (command == "deletelist") {
            getline(cin, p_name);
            manager.delete_list(trim(p_name));
        }
        else if (command == "play") {
            cin >> song_id;
            manager.play(song_id);
        }
        else if (command == "exit") {
            break;
        }
    }
}

int main()
{
    MusicManager manager;
    process_command(manager);
    return 0;
}
