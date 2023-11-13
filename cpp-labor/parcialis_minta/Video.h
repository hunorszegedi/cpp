//
// Created by szege on 12/11/2023.
//

#ifndef PARCIALIS_MINTA_VIDEO_H
#define PARCIALIS_MINTA_VIDEO_H

#include <iostream>

using namespace std;

class Video {
    string id;
    string title;
    double length;
    string uploader;
    long uploaded;
public:
    Video(const string &id, const string &title, double length, const string &uploader, long uploaded);

    const string &getId() const;

    const string &getTitle() const;

    double getLength() const;

    const string &getUploader() const;

    long getUploaded() const;

};


#endif //PARCIALIS_MINTA_VIDEO_H
