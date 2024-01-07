//
// Created by szege on 07/01/2024.
//

#ifndef PARCI2MINTABUJRA_EREMTABLAZZAT_H
#define PARCI2MINTABUJRA_EREMTABLAZZAT_H

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

class Eremtablazzat {
private:
    map<string, vector<pair<string, int>>> medalok;
public:
    Eremtablazzat(const string &filename);

    void listazas() const;

    void ujMedal(const string &nev, const string &medalTipus);

    set<string> sportolok() const;

    int medalokSzama(const string &medalTipus) const;

    string legtobbMedal();

    void keresAdottSportolo(const string &nev) {
        for (const auto &temp: medalok) {
            auto it = find_if(temp.second.begin(), temp.second.end(), [&nev](const pair<string, int> &keresett) {
                return keresett.first == nev;
            });

            if (it != temp.second.end()) {
                cout << "Sportolo neve: " << temp.first << ", Medal tipusa: " << it->first << ", Medalok szama: "
                     << it->second << endl;
            }
        }
    }

    void deleteGivenSportolo(const string &nev) {
        auto it = medalok.find(nev);
        if (it != medalok.end()) {
            medalok.erase(nev);
        } else {
            cout << "nincs benne" << endl;
        }
    }

};


#endif //PARCI2MINTABUJRA_EREMTABLAZZAT_H
