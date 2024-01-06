//
// Created by szege on 06/01/2024.
//

#ifndef LABOR12_ISMETLES_SETTLEMENT_H
#define LABOR12_ISMETLES_SETTLEMENT_H

#include <string>
#include <iostream>

using namespace std;

class Settlement {
    string name = "";
    string county = "";
    int population = 0;

public:
    Settlement(const string &name, const string &county, int population);

    Settlement();

    const string &getName() const;

    const string &getCounty() const;

    int getPopulation() const;

    void setName(const string &name);

    void setCounty(const string &county);

    void setPopulation(int population);

    friend ostream &operator<<(ostream &os, const Settlement &settlement);

    friend istream &operator>>(istream &is, Settlement &settlement);
};


#endif //LABOR12_ISMETLES_SETTLEMENT_H
