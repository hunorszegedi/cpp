//
// Created by szege on 08/12/2023.
//

#ifndef LAB9_EXTRA_BANK_H
#define LAB9_EXTRA_BANK_H

#include <string>
#include "Customer.h"

using namespace std;

class Bank {
public:
    Bank(const string &);

//returns the ID of the new Customer
    int newCustomer(const string &firstName, const string &lastName);

    bool deleteCustomer(int id);

    Customer &getCustomer(int id);

//Convenience functions
    void printCustomers(ostream &os = cout) const;

    void printCustomersAndAccounts(ostream &os = cout) const;

//LOAD customers, returns their IDs
    vector<int> loadCustomers(const string &filename);

private:
    vector<Customer> customers;
    string name;
};


#endif //LAB9_EXTRA_BANK_H
