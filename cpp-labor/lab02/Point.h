//
// Created by szege on 02/10/2023.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H


class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);

    int getX() const;

    int getY() const;
};


#endif //LAB2_POINT_H