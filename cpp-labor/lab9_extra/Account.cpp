//
// Created by szege on 08/12/2023.
//

#include "Account.h"

int Account::counter = 0;

Account::Account(double balance) {
    Account::counter++;
    this->id = counter;
    this->balance = balance;
}

void Account::deposit(double amount) {
    this->balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
        return true;
    }
    return false;
}

int Account::getId() const {
    return this->id;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::print(ostream &os) const {
    os << "Account id: " << this->id << " balance: " << this->balance;
}

ostream &operator<<(ostream &os, const Account &account) {
    account.print(os);
    return os;
}

