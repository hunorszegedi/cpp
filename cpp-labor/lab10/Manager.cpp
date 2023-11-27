//
// Created by szege on 27/11/2023.
//

#include "Manager.h"

Manager::Manager(const string &firstName, const string &lastName, int yearOfBirth, const string &position) : Employee(
        firstName, lastName, yearOfBirth, position) {
}

void Manager::addEmployee(Employee *employee) {
    employees.push_back(employee);
}

void Manager::deleteEmployee(Employee *employee) {
    for (int i = 0; i < employees.size(); ++i) {
        if (employees[i] == employee) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

int Manager::numberOfEmployees() const {
    return employees.size();
}

void Manager::print(ostream &os) const {
    Employee::print(os);
    os << "Number of employees: " << numberOfEmployees() << endl;
}

void Manager::deleteEmployeeById(int id) {
    for (int i = 0; i < employees.size(); ++i) {
        if (employees[i]->getId() == id) {
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

void Manager::printEmployees(ostream &os) const {
    for (int i = 0; i < employees.size(); ++i) {
        os << "Manager" << this->managerPosition << endl;
        os << *employees[i] << endl;
    }
}
