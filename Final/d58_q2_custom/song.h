#ifndef __SONG_H__
#define __SONG_H__

#include "priority_queue.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Song {
public:
    std::string artist, title;
    int count;

    Song() {}
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) {}
    Song(std::string artist, std::string title, int count) : artist(artist), title(title), count(count) {}

    friend std::ostream &operator<<(std::ostream &out, const Song &s) {
        return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }
};

class SongByArtistTitleCount {
public:
    bool operator()(const Song &lhs, const Song &rhs) const {
        if (lhs.artist != rhs.artist)
            return lhs.artist > rhs.artist;
        if (lhs.title != rhs.title)
            return lhs.title > rhs.title;
        return lhs.count > rhs.count;
    }
};
class SongByCountTitleArtist {
public:
    bool operator()(const Song &lhs, const Song &rhs) const {
        if (lhs.count != rhs.count)
            return lhs.count < rhs.count;
        if (lhs.artist != rhs.artist)
            return lhs.artist > rhs.artist;
        return lhs.title > rhs.title;
    }
};

//  you have to write something below this line
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song, SongByArtistTitleCount> pq1;
CP::priority_queue<Song, SongByCountTitleArtist> pq2;

#endif
