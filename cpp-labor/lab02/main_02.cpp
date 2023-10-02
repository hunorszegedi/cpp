#include "Point.h"
#include "util.h"

int main() {
    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point p2(100, 200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;

    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);

    pp1->print();
    cout << endl;
    pp2->print();
    cout << endl;

    delete pp1;
    delete pp2;

    testIsSquare("points.txt");

    srand(time(nullptr));
    int numPoints = 10;
    Point *points = createArray(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(rand() % 50, rand() % 50);
    }
    printArray(points, numPoints);
    sortPoints(points, numPoints);
    printArray(points, numPoints);

    return 0;
}
