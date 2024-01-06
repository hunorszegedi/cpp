#include <iostream>
#include "Eremtablazat.h"

int main() {

    Eremtablazat eremtablazat("input.txt");
    eremtablazat.listazas();
    set<string> sportolok = eremtablazat.sportolok();
    for (const auto &temp: sportolok) {
        cout << temp << endl;
    }
    cout << endl;
    cout << eremtablazat.legtobbMedal() << endl;
    int szam = eremtablazat.medalokSzama("");
    cout << szam;

    return 0;
}
