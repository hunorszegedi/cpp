//
// Created by szege on 16/10/2023.
//

#include <cmath>
#include "Point.h"

Point::Point(int x, int y) {
    if (x >= 0 and x <= M and y >= 0 and y <= M) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

//nehogy modositsa azert kell a const, hogy ne lehessen modositani
//az eredetit kapja meg
double Point::distanceTo(const Point &point) const {
    return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2));
}
