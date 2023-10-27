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
#include <cctype>
#include <vector>

//1
int countBitsOfAPositiveNumber(int number);

//2
bool setBit(int &number, int order);

//3
double mean(double array[], int numElements);

//4
double stddev(double array[], int size);

//5
pair<double, double> max2(double array[], int numElements);

//karakteres
int countWords(string text);

string code(string text);

string decode(string text);

string capitalizeWords(string text);

vector <string> splitWords(const string &text);


#endif //CPP_LABOR_FUNCTIONS_H
