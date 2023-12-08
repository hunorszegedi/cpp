#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Bank.h"

int main() {
//    Account account1(0);
//    cout << account1 << endl;
//    account1.deposit(1000);
//    cout << account1 << endl;
//    account1.withdraw(500);
//    cout << account1 << endl;
//    account1.withdraw(1000);
//    cout << account1 << endl;

//    cout << endl;
//
//    Customer customer1("Nagy", "Janos");
//    cout << customer1 << endl;
//    customer1.newAccount(0);
//    cout << customer1 << endl;
//    customer1.newAccount(1000);
//    cout << customer1 << endl;

    cout << endl;
    Bank bank1("OTP");
    vector<int> ids = bank1.loadCustomers("customers.txt");
    bank1.printCustomersAndAccounts();
    cout << endl;

    for (int id: ids) {
        Customer &customer = bank1.getCustomer(id);

        int accountID1 = customer.newAccount(0);
        int accountID2 = customer.newAccount(0);

        bank1.getCustomer(id).getAccount(accountID1).deposit(1000);
        bank1.getCustomer(id).getAccount(accountID2).deposit(2000);
    }

    bank1.printCustomersAndAccounts();

    bank1.getCustomer(1).getAccount(2).withdraw(230);
    bank1.getCustomer(2).getAccount(3).withdraw(130);
    bank1.printCustomersAndAccounts();

    return 0;
}
