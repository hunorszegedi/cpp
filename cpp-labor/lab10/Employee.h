//
// Created by szege on 27/11/2023.
//

#ifndef LAB10_EMPLOYEE_H
#define LAB10_EMPLOYEE_H


#include "Person.h"

class Employee : public Person {
protected:
    int id;
    static int counter;
    string position;
public:
    Employee(const string &firstName, const string &lastName, int yearOfBirth, const string &position);
    virtual void print(ostream &os) const;
    int getId() const;
};


#endif //LAB10_EMPLOYEE_H
