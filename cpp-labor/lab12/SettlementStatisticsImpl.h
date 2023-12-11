//
// Created by szege on 11/12/2023.
//

#ifndef LAB12_SETTLEMENTSTATISTICSIMPL_H
#define LAB12_SETTLEMENTSTATISTICSIMPL_H


#include <map>
#include "Settlement.h"

class SettlementStatisticsImpl : public SettlementStatistics {
    multimap<string, Settlement> settlements;
public:
    SettlementStatisticsImpl() = default;

    SettlementStatisticsImpl(const vector<Settlement> &settlements);

    virtual ~SettlementStatisticsImpl();

    virtual int numSettlements() const override;

    virtual int numCounties() const override;

    virtual int numSettlementsByCounty(const string &county) const override;

    virtual vector<Settlement> findSettlementsByCounty(
            const string &county) const override;

    virtual Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const override;

    virtual Settlement maxPopulationDensity() const override;

    virtual Settlement minPopulationDensity() const override;

    virtual vector<Settlement> findSettlementsByName(
            const string &name) override;

    void addSettlement(Settlement settlement);

    void readFromCSV(const string &fileName);
};


#endif //LAB12_SETTLEMENTSTATISTICSIMPL_H
