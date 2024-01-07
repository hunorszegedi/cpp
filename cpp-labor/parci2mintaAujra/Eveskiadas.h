//
// Created by szege on 06/01/2024.
//

#ifndef PARCI2MINTAAUJRA_EVESKIADAS_H
#define PARCI2MINTAAUJRA_EVESKIADAS_H


#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <iostream>

using namespace std;

class Eveskiadas {
private:
    map<string, vector<pair<string, int>>> kiadasok;
public:
    Eveskiadas(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "File could not open: " << filename << endl;
            exit(-1);
        }
        string honap;
        string kiadas;
        string word;
        while (file >> honap >> kiadas >> word) {
            int osszeg = stoi(word);
            kiadasok[honap].push_back(make_pair(kiadas, osszeg));
        }
    }

    void listazas() const;

    void ujKiadas(const string &honap, const string &kiadas, int osszeg);

    set<string> kiadasiKategoriak() const;

    double honaponkentiAtlagKiadas(const string &honap) const;

    double kategoriankentiAtlagKiadas() const;

};


#endif //PARCI2MINTAAUJRA_EVESKIADAS_H
