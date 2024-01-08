//
// Created by szege on 08/01/2024.
//

#ifndef PROBA_ZENESZEK_H
#define PROBA_ZENESZEK_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <fstream>

using namespace std;

class Zeneszek {
private:
    map<string, vector<pair<string, int>>> zenesz;
public:
    Zeneszek();

    Zeneszek(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "hiba file: " << filename << endl;
            exit(-1);
        }
        string nev;
        string hangszer;
        string eletkor;
        while (file >> nev >> hangszer >> eletkor) {
            int valodiEletkor = stoi(eletkor);
            hozzadas(nev, hangszer, valodiEletkor);
            cout << nev << " " << " " << hangszer << " " << eletkor << endl;
        }
        file.close();
    }

    void hozzadas(const string &nev, const string &hangszer, const int &eletkor) {
        zenesz[nev].emplace_back(hangszer, eletkor);
    }

    void listazas() {
        for (const auto &temp: zenesz) {
            cout << "\tNev: " << temp.first << endl;
            for (const auto &temp2: temp.second) {
                cout << "Hangszer: " << temp2.first << " Eve: " << temp2.second << endl;
            }
            cout << endl;
        }
    }

    string legtobbHangszer() {
        int counter = INT_MIN;
        string legtobb;
        for (const auto &temp: zenesz) {
            for (const auto &temp2: temp.second) {
                if (temp2.second > counter) {
                    counter = temp2.second;
                    legtobb = temp.first;
                }
            }
        }
        return legtobb;
    }

    void bennevan(const string &nev) {
        auto it = zenesz.find(nev);
        if (it != zenesz.end()) {
            cout << "benne van";
        } else {
            cout << "nincs benne";
        }

    }


};


#endif //PROBA_ZENESZEK_H
