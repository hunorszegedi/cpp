//
// Created by szege on 03/12/2023.
//

#ifndef LAB10_COMPANY_H
#define LAB10_COMPANY_H


#include <vector>
#include "Employee.h"
#include "Manager.h"

class Company {
public:
    Company();

    void hireEmployee(Employee *employee);

    void fireEmployee(Employee *employee);

    static void assignEmployeeToManager(Employee *employee, Manager *manager);

    void listAllEmployees(ostream &os) const;

    void listManagersOnly(ostream &os) const;

    vector<Employee *> employees;
};


#endif //LAB10_COMPANY_H
