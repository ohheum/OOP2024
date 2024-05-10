#pragma once
#include <string>
#include <vector>
using namespace std;

class Song;
class PlayList;

class MusicManager {
private:
    vector<PlayList *> playlists;
    vector<PlayList *>::iterator find_playlist(string pname);
    void add_song(Song *ptr_song, vector<string> &playlist_names);

public:
    MusicManager();
    PlayList * create_playlist(string pl_name);
    void status(ostream &out);
    void load(string filename);
    void list_playlist();
    void show_plist(string pname);
    void find_song(string keyword);
    void get_and_add_song();
    void delete_song(int songId);
    void add_to_list(int sid, string pname);
    void delete_from_list(int sid, string pname);
    void delete_list(string pname);
    void play(int sid);
};