//
// Created by szege on 06/01/2024.
//

#include "Manager.h"
#include <algorithm>

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesEve, const string &munkakor,
                 const vector<Employee *> &employees, const string &managerMunkakor) : Employee(vezetekNev, keresztNev,
                                                                                                szuletesEve, munkakor),
                                                                                       employees(employees),
                                                                                       manager_munkakor(
                                                                                               managerMunkakor) {}

void Manager::addEmployee1(Employee *a) {
    employees.push_back(a);
}

void Manager::deleteEmployee1(Employee *e) {
    auto it = remove_if(employees.begin(), employees.end(), [e](Employee *emp) {
        return e == emp;
    });
    employees.erase(it, employees.end());
}




