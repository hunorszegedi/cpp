//
// Created by szege on 12/11/2023.
//

#include "Video.h"

Video::Video(const string &id, const string &title, double length, const string &uploader, long uploaded) : id(id),
                                                                                                            title(title),
                                                                                                            length(length),
                                                                                                            uploader(
                                                                                                                    uploader),
                                                                                                            uploaded(
                                                                                                                    uploaded) {}

const string &Video::getId() const {
    return id;
}

const string &Video::getTitle() const {
    return title;
}

double Video::getLength() const {
    return length;
}

const string &Video::getUploader() const {
    return uploader;
}

long Video::getUploaded() const {
    return uploaded;
}
