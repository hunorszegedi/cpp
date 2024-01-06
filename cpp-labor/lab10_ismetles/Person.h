//
// Created by szege on 06/01/2024.
//

#ifndef PARCI2MINTAA_PERSON_H
#define PARCI2MINTAA_PERSON_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Person {
protected:
    string vezetekNev;
    string keresztNev;
    int szuletesEve;
public:
    Person(const string &vezetekNev, const string &keresztNev, int szuletesEve);

    Person();

    virtual void print1(ostream &os) const;
};

ostream &operator<<(ostream &os, const Person &person);


#endif //PARCI2MINTAA_PERSON_H
