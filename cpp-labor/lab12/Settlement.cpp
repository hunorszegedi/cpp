//
// Created by szege on 11/12/2023.
//

#include "Settlement.h"

Settlement::Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                                   population(population) {}

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
    os << "Name: " << settlement.name << endl << "County: " << settlement.county << endl << "Population: "
       << settlement.population;
    return os;
}
