//#ifndef SONG_H
//#define SONG_H
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PlayList;  // forward declaration

class Song {
private:
    int id;    // Each song object has unique id
    string title;   // object member
    string artist;
    string album;
    string mv_url;
    vector<PlayList *> playlists;
    static int id_counter;  // class member

public:
    Song();
    Song(string ti, string ar, string al, string mv);
    ~Song();

    int get_id();
    string get_title();
    string get_artist();

    void print(ostream &out);

    void register_playlist(PlayList *ptr_plist);
    void unregister_playlist(string plist_name);
    void play();
};

//#endif SONG_H
