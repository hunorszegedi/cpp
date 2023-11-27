//
// Created by szege on 27/11/2023.
//

#ifndef LAB10_MANAGER_H
#define LAB10_MANAGER_H


#include "Employee.h"
#include "vector"
#include "algorithm"

class Manager : public Employee {
public:
    const string managerPosition = "manager";
    vector<Employee *> employees;

    Manager(const string &firstName, const string &lastName, int yearOfBirth, const string &position);

    void addEmployee(Employee *employee);

    void deleteEmployee(Employee *employee);

    void deleteEmployeeById(int id);

    bool operator==(const Manager &m) const {
        return this->firstName == m.firstName && this->lastName == m.lastName && this->YearOfBirth == m.YearOfBirth &&
               this->position == m.position;
    }

    int numberOfEmployees() const;

    virtual void print(ostream &os) const;

    void printEmployees(ostream &os) const;
};


#endif //LAB10_MANAGER_H
