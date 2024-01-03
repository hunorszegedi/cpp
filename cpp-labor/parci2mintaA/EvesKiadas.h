//
// Created by szege on 03/01/2024.
//

#ifndef PARCI2MINTAA_EVESKIADAS_H
#define PARCI2MINTAA_EVESKIADAS_H

#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;


class EvesKiadas {
private:
    map<string, vector<pair<string, int>>> kiadasok;
public:
    EvesKiadas(const string &filename);

    void listazas() const;

    void ujKiadas(const string &honap, const string &kiadas, int osszeg);

    set<string> kiadasiKategoriak() const;

    double honaponkentiAtlagKiadas(const string &honap) const;

    double kategoriankentiAtlagKiadas() const;
};


#endif //PARCI2MINTAA_EVESKIADAS_H
