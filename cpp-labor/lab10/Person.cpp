//
// Created by szege on 27/11/2023.
//

#include "Person.h"

Person::Person(const string &firstName, const string &lastName, int yearOfBirth) : firstName(firstName),
                                                                                   lastName(lastName),
                                                                                   YearOfBirth(yearOfBirth) {}

void Person::print(ostream &os) const {
    os << "First name: " << firstName << endl;
    os << "Last name: " << lastName << endl;
    os << "Year of birth: " << YearOfBirth << endl;

}

Person::Person() {}

ostream &operator<<(ostream &os, const Person &person) {
    person.print(os);
    return os;
}

