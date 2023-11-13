//
// Created by szege on 12/11/2023.
//

#include "Library.h"
#include <algorithm>


Library::Library(int id, const vector<Book> &library) : ID(id), library(library) {}

int Library::getId() const {
    return ID;
}

const vector<Book> &Library::getLibrary() const {
    return library;
}

void Library::setId(int id) {
    ID = id;
}

void Library::setLibrary(const vector<Book> &library) {
    Library::library = library;
}

void Library::addBook(Book &book) {
    library.push_back(book);
}

void Library::printLibrary() {
    cout << "\tLIBRARY\t" << endl;
    for (const auto &b: library) {
        b.printBook(cout);
    }
}

const Book &Library::findBook(const string &searchTerm) {
    for (const auto &b: library) {
        if (b.getAuthor() == searchTerm or b.getTitle() == searchTerm) {
            return b;
        }
    }
//    throw exception();
    throw out_of_range("Nincs ilyen a konyvtarban!\n");
}

void Library::countBooks(const string &author) {
    int counter = 0;
    for (const auto &a: library) {
        if (a.getAuthor() == author) {
            counter++;
            a.printBook(cout);
        }
    }
    cout << "\tOSSZES KONYVE " << author << ": " << counter << endl;
}


bool compareThem(const Book &a, const Book &b) {
    // szerzo neve szerint abc sorrend
    if (a.getAuthor() != b.getAuthor()) {
        return a.getAuthor() < b.getAuthor();
    }
    // ugyanazon szerzo könyvei kiadasi ev szerint csokkeno sorrendbe
    return a.getYear() > b.getYear();
}

void Library::sortBooks() {
    sort(this->library.begin(), this->library.end(), compareThem);
}

void Library::deleteGivenBook(const string &givenTitle) {
//    for (auto it = library.begin(); it != library.end();) {
//        if (it->getTitle() == givenTitle) {
//            it = library.erase(it);  // Az erase visszaadja az új iterátort
//        } else {
//            ++it;
//        }
//    }
    int counter = 0;
    for (const auto &b: library) {
        if (b.getTitle() == givenTitle) {
            auto it = library.begin() + counter;
            library.erase(it);
        }
        counter++;
    }

}


