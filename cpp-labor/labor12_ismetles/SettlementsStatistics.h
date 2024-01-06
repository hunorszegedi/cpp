//
// Created by szege on 06/01/2024.
//

#ifndef LABOR12_ISMETLES_SETTLEMENTSSTATISTICS_H
#define LABOR12_ISMETLES_SETTLEMENTSSTATISTICS_H

#include "Settlement.h"
#include <vector>

class SettlementsStatistics {
    virtual int numSettlements() const = 0;

    virtual int numCounties() const = 0;

    virtual int numSettlementsByCounty(const string &county) const = 0;

    virtual vector<Settlement> findSettlementsByCounty(
            const string &county) const = 0;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const = 0;

    virtual Settlement maxPopulation() const = 0;

    virtual Settlement minPopulation() const = 0;

    virtual vector<Settlement> findSettlementsByName(
            const string &name) = 0;

public:
    virtual ~SettlementsStatistics() = default;
};


#endif //LABOR12_ISMETLES_SETTLEMENTSSTATISTICS_H
