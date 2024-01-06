//
// Created by szege on 05/01/2024.
//

#ifndef PARCI2MINTAB_EREMTABLAZAT_H
#define PARCI2MINTAB_EREMTABLAZAT_H

#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Eremtablazat {
private:
    map<string, vector<pair<string, int>>> medalok;
public:
    Eremtablazat(const string &filename);

    void listazas() const;

    void ujMedal(const string &nev, const string &medalTipus);

    set <string> sportolok() const;

    int medalokSzama(const string &medalTipus) const;

    string legtobbMedal();

};


#endif //PARCI2MINTAB_EREMTABLAZAT_H
