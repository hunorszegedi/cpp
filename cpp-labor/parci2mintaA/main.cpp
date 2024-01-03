#include <iostream>
#include "EvesKiadas.h"

int main() {
    EvesKiadas kiadas("minta.txt");
    kiadas.listazas();
    set valami = kiadas.kiadasiKategoriak();
    for( const auto& temp: valami){
        cout << temp << endl;
    }
    double atlag = kiadas.honaponkentiAtlagKiadas("aprilis");
    cout << atlag << endl;
    cout << kiadas.kategoriankentiAtlagKiadas() << endl;
    return 0;
}
