//
// Created by szege on 12/11/2023.
//

#ifndef LABOR6_ISMETLES_ARRAY_H
#define LABOR6_ISMETLES_ARRAY_H

#include <iostream>

using namespace std;

class Array {
private:
    int mSize;
    int *mElements;
public:
    //default
    Array(int mSize = 10);

    //copy
    Array(const Array &array);

    //move
    Array(Array &&array);

    //destruktor
    ~Array();

    //extractor >>
    friend istream &operator>>(istream &is, Array &array);

    //inserter <<
    friend ostream &operator<<(ostream &os, const Array &array);

    //+
    friend Array operator+(const Array &a, const Array &b);

    int getMSize() const;
};


#endif //LABOR6_ISMETLES_ARRAY_H
