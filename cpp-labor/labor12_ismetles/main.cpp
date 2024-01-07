#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"

int main() {
    Settlement s("Alma", "korte", 200);
    cout << s;
    Settlement s2;
//    cin >> s2;
//    cout << s2;
    SettlementStatisticsImpl impl("pelda.csv");
    impl.print();
    cout << impl.numSettlements() << endl;
    cout << impl.numCounties() << endl;
    cout << impl.numSettlementsByCounty("AB") << endl;
    vector<Settlement> bla = impl.findSettlementsByCounty("KA");
    for (const auto &temp: bla) {
        cout << temp << endl;
    }
    Settlement settlement = impl.findSettlementsByNameAndCounty("Ciuguzel", "KA");
    cout << endl << settlement;
    Settlement settlement1 = impl.maxPopulation();
    cout << endl << settlement1;

    return 0;
}
