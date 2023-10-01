//
// Created by szege on 25/09/2023.
//

#include "functions.h"

int countBitsOfAPositiveNumber(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }

    int mask = 1 << order;
    number |= mask;
    return true;
}

double mean(double array[], int numElements) {
    if (numElements <= 0) {
        return NAN;
    }

    double sum = 0;
    for (int i = 0; i < numElements; ++i) {
        sum += array[i];
    }
    double average = sum / numElements;

    return average;
}

double stddev(double array[], int numElements) {
    if (numElements <= 0) {
        return NAN;
    }

    double meanarray = mean(array, numElements);

    double sumSquaredDifferences = 0;
    for (int i = 0; i < numElements; ++i) {
        double difference = array[i] - meanarray;
        sumSquaredDifferences += difference * difference;
    }
    double variance = sumSquaredDifferences / numElements;
    double standardDeviation = sqrt(variance);

    return standardDeviation;
}

pair<double, double> max2(double array[], int numElements) {
    if (numElements <= 0) {
        return make_pair(NAN, NAN);
    } else if (numElements == 1) {
        return make_pair(array[0], array[0]);
    }


    double largest = array[0];
    double secondLargest = array[1];

    for (int i = 0; i < numElements; ++i) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } else if (array[i] > secondLargest) {
            secondLargest = array[i];
        }
    }

    return make_pair(secondLargest, largest);
}

int countWords(string text) {
    istringstream iss(text);
    int wordCount = 0;
    string word;

    while (iss >> word) {
        wordCount++;
    }

    return wordCount;
}

string code(string text) {
    for (char &c: text) {
        if (isalpha(c)) {
            if (c == 'z') {
                c = 'a';
            } else if (c == 'Z') {
                c = 'A';
            } else {
                c++;
            }
        }
    }
    return text;
}

string decode(string text) {
    for (char &c: text) {
        if (isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            } else if (c == 'A') {
                c = 'Z';
            } else {
                c--;
            }
        }
    }
    return text;
}

string capitalizeWords(string text) {
    string result;
    bool capitalizeNext = true;

    for (char c: text) {
        if (isalpha(c)) {
            if (capitalizeNext) {
                result += toupper(c);
                capitalizeNext = false;
            } else {
                result += tolower(c);
            }
        } else {
            result += c;
            capitalizeNext = true;
        }
    }

    return result;
}