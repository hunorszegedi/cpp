#include <iostream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"

int main() {
    Settlement s1("Budapest", "Pest", 1752286);
    Settlement s2("Debrecen", "Hajdu Bihar", 204124);
    Settlement s3("Szeged", "Csongrad", 161882);
    Settlement s4("Alabama", "Pest", 500);

    //SettlementStatisticsImpl implementacio
    SettlementStatisticsImpl statistics;
//    statistics.addSettlement(s1);
//    statistics.addSettlement(s2);
//    statistics.addSettlement(s3);
//    statistics.addSettlement(s4);
//    //0
//    cout << s1 << endl << endl;
//    //1
//    cout << "Number of settlements: " << statistics.numSettlements() << endl << endl;
//    //2
//    cout << "Number of counties: " << statistics.numCounties() << endl << endl;
//    //3
//    cout << "Number of settlements in Pest county: " << statistics.numSettlementsByCounty("Pest") << endl;
//    cout << "Number of settlements in Csongrad: " << statistics.numSettlementsByCounty("Csongrad") << endl << endl;
//    //4
//    cout << "\tSettlements in Pest county: " << endl;
//    vector<Settlement> settlements = statistics.findSettlementsByCounty("Pest");
//    for (auto &settlement: settlements) {
//        cout << settlement << endl << endl;
//    }
//    return 0;
    //5 read from CSV
    statistics.readFromCSV("telepulesek.csv");
    cout << "Number of settlements: " << statistics.numSettlements() << endl;
    cout << "Number of counties: " << statistics.numCounties() << endl;

    //find settlements by county
    cout << "Find settlements by county: " << endl;
    vector<Settlement> settlements = statistics.findSettlementsByCounty("AB");
    for (auto &settlement: settlements) {
        cout << settlement << endl << endl;
    }
    //41 megye kell
    //13746

    //find settlements by county and name
    cout << "Find settlements by county and name: " << endl;
    Settlement settlement = statistics.findSettlementsByNameAndCounty("Barabant", "AB");
    if (settlement.getName() == "does not exist") {
        cout << "Settlement does not exist." << endl;
    } else {
        cout << settlement << endl;
    }

    cout << endl;

    //maxPopulationDensity
    cout << "Max population density: " << endl;
    cout << statistics.maxPopulationDensity() << endl << endl;

    //minPopulationDensity
    cout << "Min population density: " << endl;
    cout << statistics.minPopulationDensity() << endl << endl;
}