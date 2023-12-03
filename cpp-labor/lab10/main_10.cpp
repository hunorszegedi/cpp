#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Company.h"

using namespace std;

int main() {

//    Employee e1("John", "Doe", 1990, "Employee");
//    e1.print(cout);
//    cout << endl;
//    Employee e2("Jane", "Doe", 1991, "Employee");
//    e2.print(cout);
//    cout << endl;
//
//    Manager m1("John", "Doe", 1990, "Manager");
//    m1.addEmployee(&e1);
//    m1.employees[0]->print(cout);
//    cout << endl;
//    m1.print(cout);
//    cout << endl;
//
////    m1.deleteEmployee(&e1);
//    m1.printEmployees(cout);
//    m1.deleteEmployeeById(1);
////    m1.print(cout);
//    cout << endl;
//
//    m1.printEmployees(cout);

    //teszteles
    Company company;

    //alkalmazottak es managerek felvetele
    for (int i = 0; i < 10; ++i) {
        if (i < 3) {
            company.hireEmployee(new Manager("Manager", "Doe", 1980 + i, "Manager"));
        } else {
            company.hireEmployee(new Employee("Employee", "Doe", 1990 + i, "Employee"));
        }
    }

    //listazas
    cout << "Employees:" << endl;
    company.listAllEmployees(cout);

    //hozzarandeles managerekhez
    for (int i = 0; i < 7; ++i) {
        Company::assignEmployeeToManager(company.employees[i], dynamic_cast<Manager *>(company.employees[i % 3]));
    }

    //csak managerek listazasa
    cout << "\n\tManagers Only:\n";
    company.listManagersOnly(cout);

    //move an employee from one manager to another
    cout << "\n\tMoving an employee from one manager to another:\n";
    auto *m1 = dynamic_cast<Manager *>(company.employees[0]);
    auto *m2 = dynamic_cast<Manager *>(company.employees[1]);
    m2->addEmployee(m1->employees[0]);
    m1->deleteEmployeeById(m1->employees[0]->getId());
    m1->printEmployees(cout);
    cout << endl;

    //csak managerek listazasa
    cout << "\nAfter moving an employee from one manager to another:\n";
    company.listManagersOnly(cout);

    //clean
    for (auto &employee: company.employees) {
        delete employee;
    }

    return 0;
}