//
// Created by szege on 16/10/2023.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H

#include "../labor2_ismetles/Point.h"

#define M 2000

class Point {
private:
    int x, y;
public:
    explicit Point(int x = 0, int y = 0);

    [[nodiscard]] int getX() const {
        return x;
    }

    [[nodiscard]] int getY() const {
        return y;
    }

};

void Point::print() const {

}

#endif //LAB2_POINT_H
