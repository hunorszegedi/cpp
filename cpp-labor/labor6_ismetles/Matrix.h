//
// Created by szege on 12/11/2023.
//

#ifndef LABOR6_ISMETLES_MATRIX_H
#define LABOR6_ISMETLES_MATRIX_H

#include <iostream>
#include <sstream>

using namespace std;

class Matrix {
public:
    //default constructor
    Matrix(int mRows = 5, int mCols = 5);

    //copy constructor
    Matrix(const Matrix &mat);

    //move constructor
    Matrix(Matrix &&mat);

    //destructor
    ~Matrix();

    //methods

    //extractor //cin
    friend istream &operator>>(istream &is, Matrix &matrix);

    //inserter //cout
    friend ostream &operator<<(ostream &os, const Matrix &matrix);

    //+
    friend Matrix operator+(const Matrix &a, const Matrix &b);

    //*
    friend Matrix operator*(const Matrix &a, const Matrix &b);

    //[]
    double *operator[](int index);

    //[] const
    double *operator[](int index) const;

    //= copy asigment
    Matrix &operator=(const Matrix &matrix);

    //= move asigment
    Matrix &operator=(Matrix &&matrix);

private:
    double **mElements;
    int mRows;
    int mCols;
};


#endif //LABOR6_ISMETLES_MATRIX_H
