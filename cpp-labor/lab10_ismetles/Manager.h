//
// Created by szege on 06/01/2024.
//

#ifndef LAB10_ISMETLES_MANAGER_H
#define LAB10_ISMETLES_MANAGER_H


#include "Employee.h"

class Manager : public Employee {
public:
    const static string manager_munkakor;

    Manager(const string &vezetekNev, const string &keresztNev, int szuletesEve, const string &munkakor);

    void addEmployee(Employee *);
};


#endif //LAB10_ISMETLES_MANAGER_H
