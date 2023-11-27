#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Manager.h"

using namespace std;

int main() {

    Employee e1("John", "Doe", 1990, "Employee");
    e1.print(cout);
    cout << endl;
    Employee e2("Jane", "Doe", 1991, "Employee");
    e2.print(cout);
    cout << endl;

    Manager m1("John", "Doe", 1990, "Manager");
    m1.addEmployee(&e1);
    m1.employees[0]->print(cout);
    cout << endl;
    m1.print(cout);
    cout << endl;

    m1.deleteEmployee(&e1);
    m1.print(cout);
    cout << endl;

    return 0;
}