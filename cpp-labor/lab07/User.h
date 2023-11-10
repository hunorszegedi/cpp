//
// Created by szege on 06/11/2023.
//

#ifndef LAB6_USER_H
#define LAB6_USER_H


#include "iostream"
#include "map"

using namespace std;

class User {
private:
    int id;
    string name;
    map<string, double> scores;
    static int counter;
public:
    User(const string &name);

    int getId() const;

    const string &getName() const;

    void addScore(const string &quizName, double score);

    double getScore(const string &quizName) const;

    void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const User &user);
};

#endif //LAB6_USER_H
