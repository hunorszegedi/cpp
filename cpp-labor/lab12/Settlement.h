//
// Created by szege on 11/12/2023.
//

#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Settlement {
    string name = "";
    string county = ""; //megye
    int population = 0; //hany lakos a megyeben
// constructor, getters, setters, inserter operator
public:
    Settlement(const string &name, const string &county, int population);

    const string &getName() const;

    const string &getCounty() const;

    int getPopulation() const;

    void setName(const string &name);

    void setCounty(const string &county);

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);

};

struct SettlementStatistics {
    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector <Settlement> findSettlementsByCounty(
            const string &county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const = 0;

    virtual Settlement maxPopulationDensity() const = 0;

    virtual Settlement minPopulationDensity() const = 0;

    virtual vector <Settlement> findSettlementsByName(
            const string &name) = 0;
};

#endif //LAB12_SETTLEMENT_H
