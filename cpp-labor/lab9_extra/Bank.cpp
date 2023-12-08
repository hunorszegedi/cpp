//
// Created by szege on 08/12/2023.
//

#include <fstream>
#include "Bank.h"

Bank::Bank(const string &name) {
    this->name = name;
}

int Bank::newCustomer(const string &firstName, const string &lastName) {
    Customer customer(firstName, lastName);
    customers.push_back(customer);
    return customer.getId();
}

bool Bank::deleteCustomer(int id) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getId() == id) {
            customers.erase(customers.begin() + i);
            return true;
        }
    }
    return false;
}

Customer &Bank::getCustomer(int id) {
    for (auto &customer: customers) {
        if (customer.getId() == id) {
            return customer;
        }
    }
    throw "Customer not found!";
}

void Bank::printCustomers(ostream &os) const {
    os << this->name << "bank" << " ugyfelei:" << endl;
    for (const auto &customer: customers) {
        os << "Ugyfel " << customer.getId() << " " << customer.getFirstName() << " " << customer.getLastName() << endl;
    }

}

void Bank::printCustomersAndAccounts(ostream &os) const {
    os << "Bank " << this->name << " ugyfelei:" << endl;
    for (const auto &customer: customers) {
        os << customer << endl;
    }
}

vector<int> Bank::loadCustomers(const string &filename) {
    ifstream file(filename);
    vector<int> ids;
    string firstName, lastName;
    while (file >> firstName >> lastName) {
        ids.push_back(newCustomer(firstName, lastName));
    }
    return ids;
}
