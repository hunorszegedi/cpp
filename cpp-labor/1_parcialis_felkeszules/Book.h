//
// Created by szege on 10/11/2023.
//

#ifndef INC_1_PARCIALIS_FELKESZULES_BOOK_H
#define INC_1_PARCIALIS_FELKESZULES_BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book {
private:
    string author;
    string title;
    int year;
    int pages;
public:
    //konstruktor default
    Book(const string &author, const string &title, int year, int pages);

    Book() = default;

    //getterek
    const string &getAuthor() const;

    const string &getTitle() const;

    int getYear() const;

    int getPages() const;

    //destrukor
    ~Book();

    //print
    static void print(ostream &os, const Book &book);

    //inserter operator a kiiratashoz
    friend ostream &operator<<(ostream &os, const Book &book);

    //csinalunke egy extraktor operatorosat is
    friend istream &operator>>(istream &is, Book &book);


};


#endif //INC_1_PARCIALIS_FELKESZULES_BOOK_H
