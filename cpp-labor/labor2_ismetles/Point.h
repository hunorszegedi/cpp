//
// Created by szege on 11/11/2023.
//

#ifndef LABOR2_ISMETLES_POINT_H
#define LABOR2_ISMETLES_POINT_H


class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {}

    Point() = default;

    ~Point() = default;

    int getX() const;

    int getY() const;

    void print() const;

    static Point *createArray(int numbPoints);
};


#endif //LABOR2_ISMETLES_POINT_H
