//
// Created by szege on 05/01/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include "Eremtablazat.h"

Eremtablazat::Eremtablazat(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }
    string nev, medalTipus;
    while (file >> nev >> medalTipus) {
        ujMedal(nev, medalTipus);
    }
}

void Eremtablazat::ujMedal(const string &nev, const string &medalTipus) {
    if (medalTipus != "arany" && medalTipus != "ezust" && medalTipus != "bronz") {
        cerr << "Hiba: Ervenytelen medal tipus: " << medalTipus << endl;
        return;
    }

    //ha nem az end iterator adja vissza, akkor benne van
    if (medalok.find(nev) != medalok.end()) {
        auto &medals = medalok[nev];
        auto it = find_if(medals.begin(), medals.end(),
                          [medalTipus](const pair<string, int> &p) { return p.first == medalTipus; });

        if (it != medals.end()) {
            it->second++;
        } else {
            // Ha még nincs ilyen típusú érme, adjon hozzá újat
            medals.emplace_back(medalTipus, 1);
        }
    } else {
        // Ha a sportoló még nem szerepelt az adatokban, adjon hozzá új bejegyzést
        medalok[nev].emplace_back(medalTipus, 1);
    }
}

void Eremtablazat::listazas() const {
    for (const auto &temp: medalok) {
        cout << "Nev: " << temp.first << endl;
        for (const auto &temp2: temp.second) {
            cout << "\t" << temp2.first << " " << temp2.second << endl;
        }
    }
}

set<string> Eremtablazat::sportolok() const {
    set<string> setSportolok;
    for (const auto &temp: medalok) {
        if (!setSportolok.contains(temp.first)) {
            setSportolok.insert(temp.first);
        }
    }
    return setSportolok;
}

string Eremtablazat::legtobbMedal() {
    string legtobbMedal;
    int maxMedalSzam = 0;
    for (const auto &temp: medalok) {
        int currentMedalSzam = 0;
        for (const auto &temp2: temp.second) {
            currentMedalSzam += temp2.second;
        }
        if (currentMedalSzam > maxMedalSzam) {
            maxMedalSzam = currentMedalSzam;
            legtobbMedal = temp.first;
        }
    }
    return legtobbMedal;
}

int Eremtablazat::medalokSzama(const string &medalTipus) const {
    if (medalTipus.empty()) {
        int counterNull = 0;
        for (const auto &temp3: medalok) {
            for (const auto &temp4: temp3.second) {
                counterNull += temp4.second;
            }
        }
        return counterNull;
    } else {
        int counter = 0;
        for (const auto &temp: medalok) {
            for (const auto &temp2: temp.second) {
                if (temp2.first == medalTipus) {
                    counter += temp2.second;
                }
            }
        }
        return counter;
    }
}
