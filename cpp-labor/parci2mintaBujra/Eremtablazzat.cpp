//
// Created by szege on 07/01/2024.
//

#include "Eremtablazzat.h"

void Eremtablazzat::listazas() const {
    for (const auto &temp: medalok) {
        cout << "\t" << temp.first << endl;
        for (const auto &temp2: temp.second) {
            cout << temp2.first << " " << temp2.second << endl;
        }
    }
}

Eremtablazzat::Eremtablazzat(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "hiba file: " << filename << endl;
        exit(-1);
    }
    string name;
    string medal;
    while (file >> name >> medal) {
        ujMedal(name, medal);
    }
    file.close();
}

void Eremtablazzat::ujMedal(const string &nev, const string &medalTipus) {
    auto &medals = medalok[nev];  // Keresd vagy hozz létre egy példányt a megadott névhez tartozó érmékből

    bool found = false;
    for (auto &temp2: medals) {
        if (medalTipus == temp2.first) {
            temp2.second++;
            found = true;
            break;
        }
    }

    if (!found) {
        medals.emplace_back(medalTipus, 1);
    }
}

set<string> Eremtablazzat::sportolok() const {
    set<string> sportolok;
    for (const auto &temp: medalok) {
        auto it = sportolok.find(temp.first);
        if (it == sportolok.end()) {
            sportolok.insert(temp.first);
        }
    }
    return sportolok;
}

int Eremtablazzat::medalokSzama(const string &medalTipus) const {
    if (!medalTipus.empty()) {
        int counter = 0;
        for (const auto &temp: medalok) {
            for (const auto &temp2: temp.second) {
                if (temp2.first == medalTipus) {
                    counter += temp2.second;
                }
            }
        }
        return counter;
    } else {
        int counterOsszesen = 0;
        for (const auto &temp: medalok) {
            for (const auto &temp2: temp.second) {
                counterOsszesen += temp2.second;
            }
        }
        return counterOsszesen;
    }
}

string Eremtablazzat::legtobbMedal() {
    string legtobb;
    int min = INT_MIN;
    for (const auto &temp: medalok) {
        int counter = 0;
        for (const auto &temp2: temp.second) {
            counter += temp2.second;
        }
        if (counter > min) {
            min = counter;
            legtobb = temp.first;
        }
    }
    return legtobb;
}


