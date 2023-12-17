//
// Created by szege on 11/12/2023.
//

#include <set>
#include <fstream>
#include <sstream>
#include <limits>
#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const vector<Settlement> &settlements) {
    for (auto &settlement: settlements) {
        this->settlements.insert(pair<string, Settlement>(settlement.getCounty(), settlement));
    }
}

SettlementStatisticsImpl::~SettlementStatisticsImpl() {
    settlements.clear();
}

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> counties;
    for (auto &settlement: settlements) {
        counties.insert(settlement.first);
    }
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> settlementsFind;
    for (auto &settlement: this->settlements) {
        if (settlement.first == county) {
            settlementsFind.push_back(settlement.second);
        }
    }
    return settlementsFind;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for (auto &settlement: settlements) {
        if (settlement.first == county && settlement.second.getName() == name) {
            return settlement.second;
        }
    }
    return Settlement("does not exist", "", 0);
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    Settlement maxDensitySettlement("", "", 0);
    int maxDensity = 0;
    for (const auto &settlement: settlements) {
        int density = settlement.second.getPopulation();
        if (density > maxDensity) {
            maxDensity = density;
            maxDensitySettlement = settlement.second;
        }
    }
    return maxDensitySettlement;
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    Settlement minDensitySettlement("", "", 0);
    int minPopulation = numeric_limits<int>::max();

    for (const auto &settlement: settlements) {
        int population = settlement.second.getPopulation();
        if (population < minPopulation) {
            minPopulation = population;
            minDensitySettlement = settlement.second;
        }
    }

    return minDensitySettlement;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for (const auto &settlement: this->settlements) {
        if (settlement.second.getName() == name) {
            result.push_back(settlement.second);
        }
    }
    return result;
}

void SettlementStatisticsImpl::addSettlement(Settlement settlement) {
    settlements.insert(pair<string, Settlement>(settlement.getCounty(), settlement));
}

void SettlementStatisticsImpl::readFromCSV(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << fileName << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
//        string name, county, population;
//        int populationNumber = 0;
//        stringstream ss(line);
//        getline(ss, name, ',');
//        getline(ss, county, ',');
//        getline(ss, population, '\n');
////        populationNumber = atoi(population);
//        Settlement settlement(name, county, populationNumber);
//        addSettlement(settlement);
        istringstream iss(line);
        string name;
        getline(iss, name, ',');
        string county;
        getline(iss, county, ',');
        string word;
        getline(iss, word);
        int population = 0;
        if (!word.empty()) {
            population = stoi(word);
        }
        Settlement settlement(name, county, population);
        addSettlement(settlement);
    }
    file.close();
}
