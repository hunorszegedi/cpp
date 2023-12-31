#include <iostream>
#include <iomanip>
#include <algorithm>
#include "PointSet.h"

using namespace std;

int main() {
    /*
    //Definíció - üres dinamikus tömb
    vector<int> v;

    //a kapacitast erinti
    //ha tudom, hogy mennyit akarok elore

    v.reserve(16);

    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;

    //Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
    for (int i = 0; i < 100; ++i) {
        v.push_back(rand() % 101);
        cout << "Size: " << v.size() << endl;
        cout << "Capacity: " << v.capacity() << endl;
    }

    //Kiíratás
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl << endl;

    //csokkeno
    sort(v.begin(), v.end(), greater<int>());
    //ezt is lehetne:
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    */

    //setw hany poziciora irja ki a szamot
    int n = 2;
    double prevMinDistance = -1; // Initialize to a value that can't be a valid distance
    bool distancesRepeating = false;

    cout << "Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok" << endl;
    cout << fixed;

    for (int i = 0; i < 12; ++i) {
        PointSet pSet(n);
        cout << setw(6) << n << " ";
        cout << setw(8) << setprecision(2) << pSet.minDistance() << " ";
        cout << setw(8) << setprecision(2) << pSet.maxDistance() << " ";
        cout << setw(10) << pSet.numDistances() << " ";
        cout << setw(16) << pSet.numDistinctDistances() << endl;

        if (pSet.minDistance() == 1) {
            cout << "Smallest n for minimum distance of 1: " << n << endl;
        }

        if (!distancesRepeating && pSet.numDistinctDistances() == prevMinDistance) {
            cout << "Distances start repeating at n: " << n << endl;
            distancesRepeating = true;
        }

        n = n << 1;
        prevMinDistance = pSet.numDistinctDistances();
    }

    return 0;
}