//
// Created by szege on 06/01/2024.
//

#ifndef LABOR12_ISMETLES_SETTLEMENTSTATISTICSIMPL_H
#define LABOR12_ISMETLES_SETTLEMENTSTATISTICSIMPL_H

#include "SettlementsStatistics.h"
#include <map>
#include <sstream>
#include <fstream>

class SettlementStatisticsImpl : public SettlementsStatistics {
    multimap<string, Settlement> settlements;
public:

    SettlementStatisticsImpl(const string &fileName) {
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "File can not be opened: " << fileName << endl;
            exit(-1);
        }
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string name;
            getline(iss, name, ',');
            string county;
            getline(iss, county, ',');
            string word;
            getline(iss, word, ',');
            int population = 0;
            if (!word.empty()) {
                population = stoi(word);
            }
            Settlement settlement(name, county, population);
            this->settlements.insert(pair<string, Settlement>(settlement.getCounty(), settlement));
        }
        file.close();
    }

    virtual int numSettlements() const override;

    virtual int numCounties() const override;

    virtual int numSettlementsByCounty(const string &county) const override;

    virtual vector<Settlement> findSettlementsByCounty(
            const string &county) const override;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const override;

    virtual Settlement maxPopulation() const override;

    virtual Settlement minPopulation() const override;

    virtual vector<Settlement> findSettlementsByName(
            const string &name) override;

    void print() {
        for (const auto &setl: this->settlements) {
            cout << setl.first << " /" << setl.second.getCounty() << " " << setl.second.getName() << " "
                 << setl.second.getPopulation() << endl;
        }
    }
};


#endif //LABOR12_ISMETLES_SETTLEMENTSTATISTICSIMPL_H
