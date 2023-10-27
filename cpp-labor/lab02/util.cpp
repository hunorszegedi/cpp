//
// Created by szege on 02/10/2023.
//

#include "util.h"
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double d1 = distance(a, b);
    double d2 = distance(b, c);
    double d3 = distance(c, d);
    double d4 = distance(d, a);
    double d5 = distance(a, c);
    double d6 = distance(b, d);

    if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d1 && d5 == d6) {
        double dot_product =
                (b.getX() - a.getX()) * (c.getX() - b.getX()) + (b.getY() - a.getY()) * (c.getY() - b.getY());
        if (dot_product == 0) {
            return true;
        }
    }
    return false;
}

void testIsSquare(const char *filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "File not found!" << endl;
        return;
    }
    while (true) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (!file) {
            break;
        }
        Point p1(x1, y1);
        Point p2(x2, y2);
        Point p3(x3, y3);
        Point p4(x4, y4);

        p1.print();
        cout << " ";
        p2.print();
        cout << " ";
        p3.print();
        cout << " ";
        p4.print();
        cout << ": ";

        if (isSquare(p1, p2, p3, p4)) {
            cout << "square" << endl;
        } else {
            cout << "not square" << endl;
        }
        cout << endl;
    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    return points;
}

void deletePoints(Point *points) {
    if (points != nullptr) {
        delete[] points;
    }
}

bool compareX(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, compareX);
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++) {
        points[i].print();
        cout << " ";
    }
    cout << endl;
}

//EXTRA
pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cerr << "Insufficient number of points to find closest points." << endl;
        return make_pair(Point(), Point());
    }

    double minDistance = distance(points[0], points[1]);
    pair<Point, Point> closestPair(points[0], points[1]);

    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }
    return closestPair;
}

//EXTRA
pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cerr << "Insufficient number of points to find farthest points." << endl;
        return make_pair(Point(), Point());
    }

    double maxDistance = distance(points[0], points[1]);
    pair<Point, Point> farthestPair(points[0], points[1]);

    for (int i = 0; i < numPoints; ++i) {
        for (int j = i + 1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist > maxDistance) {
                maxDistance = dist;
                farthestPair = make_pair(points[i], points[j]);
            }
        }
    }
    return farthestPair;
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    if (numPoints < 2) {
        cerr << "Insufficient number of points to find farthest points from origin." << endl;
        return nullptr;
    }

    Point *farthestPoints = new Point[2];
    double maxDistance = distance(Point(0, 0), points[0]);

    for (int i = 1; i < numPoints; ++i) {
        double dist = distance(Point(0, 0), points[i]);
        if (dist > maxDistance) {
            maxDistance = dist;
            farthestPoints[0] = points[i];
        }
    }

    maxDistance = distance(Point(0, 0), points[1]);

    for (int i = 2; i < numPoints; ++i) {
        double dist = distance(Point(0, 0), points[i]);
        if (dist > maxDistance) {
            maxDistance = dist;
            farthestPoints[1] = points[i];
        }
    }

    return farthestPoints;
}

