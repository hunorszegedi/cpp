//
// Created by szege on 25/09/2023.
//
#include <valarray>
#include "functions.h"

int countBits(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

double mean(int *array, int size) {
    if (size == 0) {
        // Handle the case where the array is empty to avoid division by zero
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    // Calculate the mean by dividing the sum by the number of elements
    double average = static_cast<double>(sum) / size;

    return average;

}

double stddev(int *array, int size) {
    if (size == 0) {
        return 0.0;
    }

    double mean = 0.0;
    for (int i = 0; i < size; i++) {
        mean += array[i];
    }
    mean /= size;

    double sumSquaredDiffs = 0.0;
    for (int i = 0; i < size; i++) {
        double diff = array[i] - mean;
        sumSquaredDiffs += diff * diff;
    }

    double variance = sumSquaredDiffs / size;

    double standardDeviation = sqrt(variance);

    return standardDeviation;
}