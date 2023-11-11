#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customComapare(int &a, int &b) {
    return a > b;
}

int main() {
//    vector<int> valami;
//    for (int i = 0; i < 5; ++i) {
//        int number;
//        cin >> number;
//        valami.push_back(number);
//    }
//    sort(valami.begin(), valami.end() - 3); //elso 2-t rendezi
//    for (const auto &v: valami) {
//        cout << v;
//    }
//    sort(valami.begin(), valami.end(), customComapare);
//    //&v - vel modosithato a valami tartalma
//    //v-vel nem
//    for (const auto &v: valami) {
//        cout << v;
//    }
//
//    auto legnagyobb = max_element(valami.begin(), valami.end());
//    cout << endl << *legnagyobb << endl << endl;
//    auto legkisebb = min_element(valami.begin(), valami.end());
//    cout << *legkisebb << endl;


//    vector<int> valami2;
//    for (int i = 0; i < 5; ++i) {
//        int number2;
//        cin >> number2;
//        valami2.emplace_back(number2);
//    }
//    cout << endl;
//    auto last = unique(valami2.begin(), valami2.end()); //nem torli csak a vegere tologatja
//    cout << "last: " << *last << endl;
//    cout << endl;
//    for (const auto &e: valami2) {
//        cout << e << " ";
//    }
//
//    valami2.erase(last, valami2.end());
//    cout << "Eltavolitott elemek: ";
//    for (const auto &v: valami2) {
//        cout << v << " ";
//    }
//    cout << endl;
//    vector<int> dinTomb = {1, 2, 2, 2, 3, 4, 5};
//    auto last = unique(dinTomb.begin(), dinTomb.end());
//    for (const auto &v: dinTomb) {
//        cout << v << " ";
//    }
//    cout << endl;
//    cout << *last << endl;
//    cout << endl;
//    dinTomb.erase(last, dinTomb.end());
//    for (const auto &v: dinTomb) {
//        cout << v << " ";
//    }
//    cout << endl;
//    cout << *last << endl;
    vector<int> myVector;

    // Előre lefoglal 10 helyet a vektor memóriájában
    myVector.reserve(10);

    // Hozzáad elemeket a vektorhoz
    for (int i = 1; i <= 5; ++i) {
        myVector.push_back(i);
    }

    cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << endl;

    return 0;
}
