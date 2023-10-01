//
// Created by szege on 25/09/2023.
//

#ifndef CPP_LABOR_FUNCTIONS_H
#define CPP_LABOR_FUNCTIONS_H


using namespace std;

#include <valarray>
#include <iostream>
#include <sstream>
#include <cmath>
#include <utility>

//1.Feladat
int countBitsOfAPositiveNumber(int number);

//2.Feladat
bool setBit(int &number, int order);

//3
double mean(double array[], int numElements);

//4
double stddev(double array[], int size);

//5
pair<double, double> max2(double array[], int numElements);

//1
double valami(int a, int b);


#endif //CPP_LABOR_FUNCTIONS_H
