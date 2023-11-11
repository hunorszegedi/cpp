#include <iostream>
#include "Point.h"

using namespace std;

int main() {
//    Point p1(2, 3);
//    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
//    Point p2(100, 200);
//    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
//    Point *pp1 = new Point(300, 400);
//    Point *pp2 = new Point(500, 1000);
//    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
//    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;
//    p1.print();
//    pp1->print();
//    delete pp1;
//    delete pp2;
    Point point1(2, 3);
    Point *point11 = new Point(3, 9);
    point1.print();
    Point *valami = Point::createArray(50);
    valami[0].print();
    valami[0] = Point(100, 200);
    valami[0].print();
    point11->print();
    delete point11;
    delete[] valami;
    return 0;
}