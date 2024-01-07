//
// Created by szege on 06/01/2024.
//

#include "Eveskiadas.h"

void Eveskiadas::listazas() const {
    for (const auto &temp: kiadasok) {
        cout << "\t" << temp.first << endl;
        for (const auto &temp2: temp.second) {
            cout << temp2.first << " " << temp2.second << endl;
        }
        cout << endl;
    }
}

void Eveskiadas::ujKiadas(const string &honap, const string &kiadas, int osszeg) {
    kiadasok[honap].push_back(make_pair(kiadas, osszeg));
}

set<string> Eveskiadas::kiadasiKategoriak() const {
    set<string> kiadasK;
    for (const auto &temp: kiadasok) {
        for (const auto &temp2: temp.second) {
            kiadasK.insert(temp2.first);
        }
    }
    return kiadasK;
}

double Eveskiadas::honaponkentiAtlagKiadas(const string &honap) const {
    if (!honap.empty()) {
        double atlagK = 0;
        auto it = kiadasok.find(honap);
        if (it != kiadasok.end()) {
            for (const auto &temp: it->second) {
                atlagK += temp.second;
            }
        }
        return atlagK;
    } else {
        double atlagOsszes = 0;
        for (const auto &temp: kiadasok) {
            for (const auto &temp2: temp.second) {
                atlagOsszes += temp2.second;
            }
        }
        return atlagOsszes;
    }
}

double Eveskiadas::kategoriankentiAtlagKiadas() const {
    set<string> kiadasKategoriak = kiadasiKategoriak();

    for (const auto &temp: kiadasKategoriak) {
        cout << "\t" << temp << endl;
        for (const auto &havikiadas: kiadasok) {
            for (const auto &kiadas: havikiadas.second) {
                if (kiadas.first == temp) {
                    cout << havikiadas.first << " " << kiadas.second << endl;
                }
            }
        }
    }
    return 0;
}
