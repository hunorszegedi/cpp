//
// Created by szege on 30/10/2023.
//

#include "Matrix.h"

//this-> blabla is lehetne
Matrix::Matrix(int mRows, int mCols) : mRows(mRows), mCols(mCols) {
    //helyfoglalas
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        this->mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    cout << "Move constructor" << endl;
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;
    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

Matrix::~Matrix() {
//    cout << " Destructor" << endl;
    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] not_eq nullptr)
            delete[]mElements[i]; //delete[] egyuttesen az operator a []-vel

    }
    if (mElements not_eq nullptr) delete[]mElements;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = rand() % (b - a) + a;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.getRows() == y.getRows() and x.getCols() == y.getCols()) {
        Matrix sumMatrix(x.getRows(), x.getCols());
        for (int i = 0; i < sumMatrix.getRows(); ++i) {
            for (int j = 0; j < sumMatrix.getCols(); ++j) {
                sumMatrix.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
            }
        }
        return sumMatrix;
    } else
        throw out_of_range("+ operation is permitted on matrices having the same dimensions!");
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.getRows() == y.getCols()) {
        Matrix multMatrix(x.getRows(), y.getCols());
        for (int i = 0; i < multMatrix.getRows(); ++i) {
            for (int j = 0; j < multMatrix.getCols(); ++j) {
                double sum = 0.0;
                for (int k = 0; k < x.getCols(); ++k) {
                    sum += x.mElements[i][k] * y.mElements[k][j];
                }
                multMatrix.mElements[i][j] = sum;
            }
        }
        return multMatrix;
    } else {
        throw out_of_range("* operation is permitted on matrices having proper dimensions!");
    }
}

istream &operator>>(istream &is, Matrix &mat) {
    int mRows, mCols;
    is >> mRows >> mCols;

    mat.mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mat.mElements[i] = new double[mCols];
    }

    mat.mRows = mRows;
    mat.mCols = mCols;

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }

    return is;
}


ostream &operator<<(ostream &os, const Matrix &mat) {
    os << mat.mRows << " " << mat.mCols << endl;
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }

    return os;
}

double *Matrix::operator[](int index) {
    if (index < 0 or index >= mRows) {
        throw out_of_range("Index out of range!");
    }
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    if (index < 0 or index >= mRows) {
        throw out_of_range("Index out of range!");
    }
    return mElements[index];
}

Matrix Matrix::operator=(const Matrix &mat) {
    if (this == &mat) return *this;

    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] not_eq nullptr) delete[]mElements[i];
    }

    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements[i] = new double[mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = mat.mElements[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    cout << "Move assignment" << endl;
    if (this == &mat) return *this;

    for (int i = 0; i < mRows; ++i) {
        if (mElements[i] not_eq nullptr) delete[]mElements[i];
    }
    if (mElements not_eq nullptr) delete[]mElements;

    mRows = mat.mRows;
    mCols = mat.mCols;
    mElements = mat.mElements;
    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;

    return *this;
}
