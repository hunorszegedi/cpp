//
// Created by szege on 06/01/2024.
//

#include "SettlementStatisticsImpl.h"
#include <set>

int SettlementStatisticsImpl::numSettlements() const {
    return this->settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> counties;
    for (const auto &temp: settlements) {
        counties.insert(temp.second.getCounty());
    }
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
//    int counter = 0;
//    for (const auto &temp: settlements) {
//        if (temp.second.getCounty() == county) {
//            counter++;
//        }
//    }
//    return counter;
    return settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> setbycounty;
    for (const auto &temp: settlements) {
        if (temp.second.getCounty() == county) {
            setbycounty.push_back(temp.second);
        }
    }
    return setbycounty;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for (const auto &temp: settlements) {
        if (temp.second.getName() == name and temp.second.getCounty() == county) {
            Settlement settlement(temp.second.getName(), temp.second.getCounty(), temp.second.getPopulation());
            return settlement;
        }
    }
}

Settlement SettlementStatisticsImpl::maxPopulation() const {
    int min = INT_MIN;
    Settlement settlement;
    for (const auto &temp: settlements) {
        if (temp.second.getPopulation() > min) {
            min = temp.second.getPopulation();
            settlement = Settlement(temp.second.getName(), temp.second.getCounty(), temp.second.getPopulation());

        }
    }
    return settlement;
}

Settlement SettlementStatisticsImpl::minPopulation() const {
    int max = INT_MAX;
    Settlement settlement;
    for (const auto &temp: settlements) {
        if (temp.second.getPopulation() < max) {
            max = temp.second.getPopulation();
            settlement = Settlement(temp.second.getName(), temp.second.getCounty(), temp.second.getPopulation());
        }
    }
    return settlement;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> setByName;
    for (const auto &temp: settlements) {
        if (temp.second.getName() == name) {
            setByName.push_back(temp.second);
        }
    }
    return setByName;
}
