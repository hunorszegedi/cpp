//
// Created by szege on 10/11/2023.
//

#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(const string &author, const string &title, int year, int pages) : author(author), title(title), year(year),
                                                                             pages(pages) {}

Book::~Book() = default;

const string &Book::getAuthor() const {
    return author;
}

const string &Book::getTitle() const {
    return title;
}

int Book::getYear() const {
    return year;
}

int Book::getPages() const {
    return pages;
}

void Book::print(ostream &os, const Book &book) {
    os << "A konyv szerzoje: " << book.getAuthor() << endl;
    os << "A kony cime: " << book.getTitle() << endl;
    os << "A konyv kiadasi eve: " << book.getYear() << endl;
    os << "A konyv oldalainak szama: " << book.getPages() << endl;
}

ostream &operator<<(ostream &os, const Book &book) {
    book.print(os, book);
    return os;
}

istream &operator>>(istream &is, Book &book) {
    cout << "A konyv szerzoje:";
    getline(is, book.author);
    cout << "A kony cime:";
    getline(is, book.title);
    cout << "A konyv kiadasi eve:";
    is >> book.year;
    cout << "A konyv oldalainak szama:";
    is >> book.pages;
    return is;
}
