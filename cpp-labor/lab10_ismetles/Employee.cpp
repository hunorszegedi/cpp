//
// Created by szege on 06/01/2024.
//

#include "Employee.h"

int Employee::szam = 0;

Employee::Employee(const string &vezetekNev, const string &keresztNev, int szuletesEve, const string &munkakor)
        : Person(vezetekNev, keresztNev, szuletesEve) {
    Employee::szam++;
    this->id = szam;
    this->munkakor = munkakor;

}

void Employee::print1(ostream &os) const {
    Person::print1(os);
    cout << " " << munkakor << " " << id << endl;
}


