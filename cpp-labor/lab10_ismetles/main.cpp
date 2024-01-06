#include <iostream>
#include "Employee.h"
#include "Manager.h"
int main() {

    Employee employee("Nagy", "Karoly", 2000, "munkas");
    employee.print1(cout);
    Employee employee2("Nagy", "Karoly", 2000, "munkas");
    employee2.print1(cout);
    Manager manager("Nagy", "Karoly", 2000, "munkas", vector<Employee *>());

    return 0;
}
