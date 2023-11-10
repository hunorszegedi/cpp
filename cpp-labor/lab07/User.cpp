//
// Created by szege on 06/11/2023.
//

#include "User.h"

int User::counter = 0;

User::User(const string &name) : name(name), id(counter++) {}

int User::getId() const { return id; }

const string &User::getName() const { return name; }

void User::addScore(const string &quizName, double score) {
    scores.insert(pair<string, double>(quizName, score));
}

double User::getScore(const string &quizName) const { return scores.at(quizName); }

void User::print(ostream &os) const {
    os << "User: " << name << " id: " << id << endl;
    for (auto &score: scores) {
        os << score.first << " " << score.second << endl;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    user.print(os);
    return os;
}

