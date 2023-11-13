//
// Created by szege on 12/11/2023.
//

#ifndef PARCIALIS_MINTA_LIBRARY_H
#define PARCIALIS_MINTA_LIBRARY_H

#include "Book.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

class Library {
private:
    int ID;
    vector<Book> library;
public:
    Library(int id, const vector<Book> &library);

    Library();

    Library(int id) : ID(id) {};

    int getId() const;

    const vector<Book> &getLibrary() const;

    void setId(int id);

    void setLibrary(const vector<Book> &library);

    void addBook(Book &book);

    void printLibrary();

    const Book &findBook(const string &searchTerm);

    void countBooks(const string &author);

    void sortBooks();

    void deleteGivenBook(const string &givenTitle);
};


#endif //PARCIALIS_MINTA_LIBRARY_H
