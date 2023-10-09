//
// Created by szege on 02/10/2023.
//

#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::print() const {
    cout << "(" << this->x << "," << this->y << ")" << endl;
}

void Point::setX(int x) {
    if (x >= 0 && x <= 2000) {
        this->x = x;
    }
}

void Point::setY(int y) {
    if (y >= 0 && y <= 2000) {
        this->y = y;
    }
}


