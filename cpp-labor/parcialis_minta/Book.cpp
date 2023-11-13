//
// Created by szege on 12/11/2023.
//

#include "Book.h"

Book::Book(const string &author, const string &title, int year, int pages) : author(author), title(title), year(year),
                                                                             pages(pages) {}

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

void Book::printBook(ostream &os) const {
    os << "A konyv szerzoje: " << author << endl;
    os << "A konyv cime: " << title << endl;
    os << "A konyv kiadasi eve " << year << endl;
    os << "A konyv oldalainak szama: " << pages << endl << endl;
}

ostream &operator<<(ostream &os, const Book &book) {
    book.printBook(os);
    return os;
}

