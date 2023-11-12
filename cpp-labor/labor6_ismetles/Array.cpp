//
// Created by szege on 12/11/2023.
//

#include "Array.h"

Array::Array(int mSize) : mSize(mSize) {
    this->mElements = new int[mSize];
}


Array::~Array() {
    cout << "Destructor" << endl;
    delete[] this->mElements;
    this->mSize = 0;
}

Array::Array(const Array &array) {
    this->mSize = array.mSize;
    this->mElements = new int[array.mSize];
    for (int i = 0; i < mSize; ++i) {
        this->mElements[i] = array.mElements[i];
    }
}

Array::Array(Array &&array) {
    this->mSize = array.mSize;
    this->mElements = array.mElements;
    array.mSize = 0;
    array.mElements = nullptr;
}

istream &operator>>(istream &is, Array &array) {
    int mSize;
    cout << "Size:";
    is >> mSize;
    array.mSize = mSize;
    array.mElements = new int[array.mSize];
    for (int i = 0; i < array.mSize; ++i) {
        is >> array.mElements[i];
    }
    return is;
}

Array operator+(const Array &a, const Array &b) {
    Array result(a.mSize + b.mSize);
    for (int i = 0; i < a.mSize; ++i) {
        result.mElements[i] = a.mElements[i];
    }
    for (int i = 0; i < b.mSize; ++i) {
        result.mElements[i + a.mSize] = b.mElements[i];
    }
    return result;
}

ostream &operator<<(ostream &os, const Array &array) {
    for (int i = 0; i < array.mSize; ++i) {
        os << array.mElements[i] << " ";
    }
    return os;
}
