//
// Created by szege on 06/01/2024.
//

#ifndef LAB10_ISMETLES_MANAGER_H
#define LAB10_ISMETLES_MANAGER_H


#include "Employee.h"

class Manager : public Employee {
public:
    vector<Employee *> employees;
    const string manager_munkakor = "manager";

    Manager(const string &vezetekNev, const string &keresztNev, int szuletesEve, const string &munkakor,
            const vector<Employee *> &employees, const string &managerMunkakor);

    void addEmployee1(Employee *);
    void deleteEmployee1(Employee *);
};


#endif //LAB10_ISMETLES_MANAGER_H
