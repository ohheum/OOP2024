#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Song;  // forward declaration

class PlayList {
private:
    string name;
    vector<Song *> tracks;
public:
    PlayList() = default;
    PlayList(string str);
    string get_name();

    void add_song(Song *song);
    void print(ostream &out);

    vector<Song *> find_songs_by_keyword(string keyword);
    Song *find_song_by_id(int sid);

    void delete_song_by_id(int songId);
    void clear_songs();
    int size();
};