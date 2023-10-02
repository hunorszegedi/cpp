//
// Created by szege on 02/10/2023.
//

#ifndef LAB2_UTIL_H
#define LAB2_UTIL_H

#include "Point.h"

double distance(const Point &a, const Point &b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void deletePoints(Point* points);
void sortPoints(Point* points, int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);




#endif //LAB2_UTIL_H
