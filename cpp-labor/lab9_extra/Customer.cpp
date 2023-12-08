//
// Created by szege on 08/12/2023.
//

#include "Customer.h"

int Customer::counter = 0;

Customer::Customer(const string &firstName, const string &lastName) {
    Customer::counter++;
    this->id = counter;
    this->firstName = firstName;
    this->lastName = lastName;
}

const string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const string &firstName) {
    Customer::firstName = firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const string &lastName) {
    Customer::lastName = lastName;
}

Account &Customer::getAccount(int id) {
    for (auto &account: accounts) {
        if (account.getId() == id) {
            return account;
        }
    }
    throw "Account not found!";
}

int Customer::newAccount(double balance) {
    Account account(balance);
    accounts.push_back(account);
    return account.getId();
}

bool Customer::deleteAccount(int id) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getId() == id) {
            accounts.erase(accounts.begin() + i);
            return true;
        }
    }
    return false;
}

int Customer::getNumAccounts() const {
    return accounts.size();
}

void Customer::print(ostream &os) const {
    os << this->id << " | " << this->firstName << " " << this->lastName << endl;
    for (auto account: accounts) {
        os << "\t" << account << endl;
    }
}

ostream &operator<<(ostream &os, const Customer &customer) {
    customer.print(os);
    return os;
}

Account &Customer::operator[](int index) {
    return accounts[index];
}

const Account &Customer::operator[](int index) const {
    return accounts[index];
}
