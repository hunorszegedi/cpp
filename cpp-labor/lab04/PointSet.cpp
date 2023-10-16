//
// Created by szege on 16/10/2023.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

using namespace std;

PointSet::PointSet(int n) {
    this->n = n;
    this->points.reserve(n);
    this->distances.reserve(n * (n - 1) / 2);
    //csak kulonbozo pontok

    random_device rd; //seed the random generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); //return the number in the given range

    bool exists[M + 1][M + 1]{false};

    while (points.size() < n) {
        int x = dist(mt);
        int y = dist(mt);
        points.emplace_back(x, y);
        //vagy igy is lehet, az emplace back ujabb
        //points.push_back(Point(x, y));
    }
    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return n * (n - 1) / 2;
}

void PointSet::printPoints() const {
    for (int i = 0; i < points.size(); ++i) {
        cout << points[i].getX() << " " << points[i].getY() << endl;
    }
}

void PointSet::printDistances() const {
    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << " ";
    }
    cout << endl;
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.getX() < b.getX();
    });
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.getY() < b.getY();
    });
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    return distance(distances.begin(), unique(distances.begin(), distances.end()));
}

