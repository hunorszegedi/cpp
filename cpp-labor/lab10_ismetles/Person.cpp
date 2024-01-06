//
// Created by szege on 06/01/2024.
//

#include "Person.h"

Person::Person(const string &vezetekNev, const string &keresztNev, int szuletesEve) : vezetekNev(vezetekNev),
                                                                                      keresztNev(keresztNev),
                                                                                      szuletesEve(szuletesEve) {}

void Person::print1(ostream &os) const {
    os << vezetekNev << " " << keresztNev << " " << szuletesEve;
}

Person::Person() {}

ostream &operator<<(ostream &os, const Person &person) {
    person.print1(os);
    return os;
}