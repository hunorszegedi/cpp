//
// Created by szege on 16/10/2023.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H
#define M 2000


class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);

    [[nodiscard]] int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    double distanceTo(const Point &point) const;
};

#endif //LAB2_POINT_H