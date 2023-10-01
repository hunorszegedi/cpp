#include <iostream>
#include <sstream>
#include "functions.h"

using namespace std;

int main(int argc, char *argv[]) {

    double sum = 0;
    for (int i = 0; i < argc; ++i) {
        istringstream iss(argv[i]);
        double value = 0;
        iss >> value;
        if (!iss) {
            cerr << "Invalid argument: " << argv[i] << endl;
        } else {
            sum += value;
        }
    }
    cout << sum << endl;

//    int n = 7;
//    cout << "The number of bits in " << n << " is " << countBits(n) << endl;
//    n = 8;
//    cout << "The number of bits in " << n << " is " << countBits(n) << endl;
//    cout << "The code for the mean function" << endl;
//    int array[] = {1, 2, 3, 4, 5};
//    int size = sizeof(array) / sizeof(array[0]);
//    cout << mean(array, size) << endl;
//    cout << "The code for the stddev function" << endl;
//    cout << stddev(array, size) << endl;

    return 0;

}