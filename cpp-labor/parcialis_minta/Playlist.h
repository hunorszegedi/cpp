//
// Created by szege on 12/11/2023.
//

#ifndef PARCIALIS_MINTA_PLAYLIST_H
#define PARCIALIS_MINTA_PLAYLIST_H


#include <vector>
#include "Video.h"

class Playlist {
    vector <Video> playlist;

public:
    Playlist() = default;

    explicit Playlist(const vector<Video> &playlist);
};


#endif //PARCIALIS_MINTA_PLAYLIST_H
