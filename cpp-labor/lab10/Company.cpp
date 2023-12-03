//
// Created by szege on 03/12/2023.
//

#include "Company.h"

Company::Company() = default;

void Company::hireEmployee(Employee *employee) {
    employees.push_back(employee);
}

void Company::fireEmployee(Employee *employee) {
    for (int i = 0; i < employees.size(); ++i) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

void Company::assignEmployeeToManager(Employee *employee, Manager *manager) {
    manager->addEmployee(employee);
}

void Company::listAllEmployees(ostream &os) const {
    for (const auto &employee: employees) {
        employee->print(os);
        os << endl;
    }
}

void Company::listManagersOnly(ostream &os) const {
    for (const auto &employee: employees) {
        if (dynamic_cast<Manager *>(employee) != nullptr) {
            employee->print(os);
            os << endl;
        }
    }
}
