#include <iostream>
#include "Eveskiadas.h"

int main() {

    Eveskiadas eveskiadas("input.txt");
    eveskiadas.listazas();
    eveskiadas.ujKiadas("marcius", "rokagombakoltes", 1234);
    eveskiadas.listazas();
    set<string> kiadasK = eveskiadas.kiadasiKategoriak();
    for (const auto &temp: kiadasK) {
        cout << temp << " ";
    }
    cout << endl;
    double atlagK = eveskiadas.honaponkentiAtlagKiadas("");
    cout << "Atlag: " << atlagK;
    cout << endl;
    eveskiadas.kategoriankentiAtlagKiadas();
    return 0;
}
