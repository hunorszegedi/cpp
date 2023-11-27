//
// Created by szege on 27/11/2023.
//

#include "Employee.h"

int Employee::counter = 0;

Employee::Employee(const string &firstName, const string &lastName, int yearOfBirth, const string &position): Person (firstName, lastName, yearOfBirth){
    Employee::counter++;
    this->position = position;
    this->id = counter;
}

void Employee::print(ostream &os) const {
    Person::print(os);
    os << "Position: " << position << endl;
    os << "ID: " << id << endl;
}

int Employee::getId() const {
    return id;
}
