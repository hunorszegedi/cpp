//
// Created by szege on 12/11/2023.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &mat) {
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&mat) {
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] not_eq nullptr) {
            delete[] mElements[i];
        }
    }
    if (mElements not_eq nullptr) {
        delete[] mElements;
    }
}

istream &operator>>(istream &is, Matrix &matrix) {
    int mRows, mCols;
    is >> mRows >> mCols;
    matrix.mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        matrix.mElements[i] = new double[mCols];
    }
    matrix.mRows = mRows;
    matrix.mCols = mCols;
    for (int i = 0; i < matrix.mRows; ++i) {
        for (int j = 0; j < matrix.mCols; ++j) {
            is >> matrix.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &matrix) {
    os << matrix.mRows << " " << matrix.mCols << endl;
    for (int i = 0; i < matrix.mRows; ++i) {
        for (int j = 0; j < matrix.mCols; ++j) {
            os << matrix.mElements[i][j] << " ";
        }
        cout << endl;
    }
    return os;
}

double *Matrix::operator[](int index) {
    if (index < 0 or index > mRows) {
        throw out_of_range("INDEX OUT OF RANGE");
    }
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 or mRows > index) {
        throw out_of_range("INDEX OUT OF RANGE");
    }
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix) return *this;
    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] not_eq nullptr) delete[]mElements[i];
    }
    mRows = matrix.mRows;
    mCols = matrix.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < this->mRows; ++i) {
        mElements[i] = new double[this->mCols];
    }
    for (int i = 0; i < this->mRows; ++i) {
        for (int j = 0; j < this->mCols; ++j) {
            mElements[i][j] = matrix.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&matrix) {
    if (this == &matrix) return *this;
    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] not_eq nullptr) delete[]mElements[i];
    }
    if (mElements not_eq nullptr) delete[] mElements;
    mRows = matrix.mRows;
    mCols = matrix.mCols;
    mElements = matrix.mElements;
    matrix.mRows = 0;
    matrix.mCols = 0;
    matrix.mElements = nullptr;
    return *this;
}


