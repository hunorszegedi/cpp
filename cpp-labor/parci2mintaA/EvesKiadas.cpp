//
// Created by szege on 03/01/2024.
//

#include "EvesKiadas.h"
#include <fstream>
#include <iostream>
#include <sstream>

EvesKiadas::EvesKiadas(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string honap;
        string kiadas;
        int osszeg;
        iss >> honap >> kiadas >> osszeg;
        ujKiadas(honap, kiadas, osszeg);
    }
}

void EvesKiadas::listazas() const {
    for (const auto &temp: kiadasok) {
        cout << "<" << temp.first << ">" << endl;
        for (const auto &kiadas: temp.second) {
            cout << "\t - <" << kiadas.first << ">: " << kiadas.second << endl;
        }
    }
}

void EvesKiadas::ujKiadas(const string &honap, const string &kiadas, int osszeg) {
    if (kiadasok.find(honap) == kiadasok.end()) {
        kiadasok[honap] = vector<pair<string, int>>();
    }
    kiadasok[honap].push_back(make_pair(kiadas, osszeg));
}

set<string> EvesKiadas::kiadasiKategoriak() const {
    set<string> kategoriak;
    for (const auto &temp: kiadasok) {
        for (const auto &temp2: temp.second) {
            if (!kategoriak.contains(temp2.first)) {
                kategoriak.insert(temp2.first);
            }
        }
    }
    return kategoriak;
}

double EvesKiadas::honaponkentiAtlagKiadas(const string &honap) const {
    if (kiadasok.find(honap) != kiadasok.end()) {
        double counter = 0;
        double sum = 0;
        for (const auto &temp: kiadasok.find(honap)->second) {
            counter++;
            sum += temp.second;
        }
        cout << honap << ": " << endl;
        return sum / counter;
    } else if (honap.empty()) {
        double counter = 0;
        double sum = 0;
        for (const auto &temp: kiadasok) {
            for (const auto &temp2: temp.second) {
                counter++;
                sum += temp2.second;
            }
        }
        cout << "Atlag: " << endl;
        return sum / counter;
    } else {
        return 0;
    }
}

double EvesKiadas::kategoriankentiAtlagKiadas() const {
    set<string> kategoriak = kiadasiKategoriak();
    for (const auto &kategoria : kategoriak) {
        cout << kategoria << ": " << endl;
        double counter = 0;
        double sum = 0;
        for (const auto &temp : kiadasok) {
            for (const auto &temp2 : temp.second) {
                if (temp2.first == kategoria) {
                    counter++;
                    sum += temp2.second;
                }
            }
        }
        if (counter != 0) {
            cout << "Atlag: " << sum / counter << endl;
        } else {
            cout << "Nincs adat a kategóriában." << endl;
        }
    }
    return 0;
}
