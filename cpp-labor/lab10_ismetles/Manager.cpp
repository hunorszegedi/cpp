//
// Created by szege on 06/01/2024.
//

#include "Manager.h"

const string Manager::manager_munkakor = "manager";

Manager::Manager(const string &vezetekNev, const string &keresztNev, int szuletesEve, const string &munkakor)
        : Employee(vezetekNev, keresztNev, szuletesEve, munkakor) {}

void addEmployee(Employee *) {

}
