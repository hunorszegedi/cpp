//
// Created by szege on 11/11/2023.
//

#include "Point.h"
#include <iostream>

using namespace std;

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << x << " " << y << endl;
}

Point *Point::createArray(int numbPoints) {
    Point *points = new Point[numbPoints];
    return points;
}


