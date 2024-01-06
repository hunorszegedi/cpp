//
// Created by szege on 06/01/2024.
//

#include "Settlement.h"

Settlement::Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                                   population(population) {}

Settlement::Settlement() = default;

const string &Settlement::getName() const {
    return name;
}

const string &Settlement::getCounty() const {
    return county;
}

int Settlement::getPopulation() const {
    return population;
}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

ostream &operator<<(ostream &os, const Settlement &settlement) {
    os << settlement.name << " " << settlement.county << " " << settlement.population << endl;
    return os;
}

istream &operator>>(istream &is, Settlement &settlement) {
    is >> settlement.name >> settlement.county >> settlement.population;
    return is;
}
