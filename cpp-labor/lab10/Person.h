//
// Created by szege on 27/11/2023.
//

#ifndef LAB10_PERSON_H
#define LAB10_PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    int YearOfBirth;
public:

    Person(const string &firstName, const string &lastName, int yearOfBirth);

    Person();

    virtual void print(ostream &os) const;

};

ostream &operator<<(ostream &os, const Person &person);

#endif //LAB10_PERSON_H
