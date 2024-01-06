//
// Created by szege on 06/01/2024.
//

#ifndef LAB10_ISMETLES_EMPLOYEE_H
#define LAB10_ISMETLES_EMPLOYEE_H


#include <ostream>
#include "Person.h"

class Employee : public Person {
protected:
    int id;
    string munkakor;
    static int szam;
public:
    Employee(const string &vezetekNev, const string &keresztNev, int szuletesEve, const string &munkakor);

    virtual void print1(ostream &os) const;
};


#endif //LAB10_ISMETLES_EMPLOYEE_H
