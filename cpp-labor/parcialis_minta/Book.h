//
// Created by szege on 12/11/2023.
//

#ifndef PARCIALIS_MINTA_BOOK_H
#define PARCIALIS_MINTA_BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string title;
    int year;
    int pages;
public:
    Book(const string &author, const string &title, int year, int pages);

    const string &getAuthor() const;

    const string &getTitle() const;

    int getYear() const;

    int getPages() const;

    void printBook(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Book &book);

    Book() = default;

    bool operator==(const Book &other) const {
        return title == other.title && author == other.author && year == other.year && pages == other.pages;
    }
};


#endif //PARCIALIS_MINTA_BOOK_H
