#include "Eremtablazzat.h"

int main() {
//    Eremtablazzat eremtablazzat("input.txt");
//    cout << endl;
//
//    eremtablazzat.listazas();
//    cout << endl;
//
//    set<string> sportolok = eremtablazzat.sportolok();
//    for (const auto &nev: sportolok) {
//        cout << nev << endl;
//    }
//    cout << endl;
//
//    cout << "Medalok szama: " << eremtablazzat.medalokSzama("arany");
//    cout << endl;
//
//    cout << "Legtobb: " << eremtablazzat.legtobbMedal();
//    cout << endl;
//
//    eremtablazzat.deleteGivenSportolo("Toth");
//    eremtablazzat.listazas();
//    cout << endl;

    map<string, vector<pair<string, int>>> temp;
    temp.insert({"a", {}});
    temp.insert({"b", {{"alma", 3}}});
    temp["c"] = {{"korte", 3}};
    temp.insert({"d", {{"valami", 2}}});
    auto it = temp.find("d");
    if (it != temp.end()) {
        cout << it->first << endl;
        for (const auto &foo: it->second) {
            cout << foo.first << " " << foo.second << endl;
        }
    }

    return 0;
}
