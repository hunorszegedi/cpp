//
// Created by szege on 04/12/2023.
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return firstName;
}

const string &Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades.insert(pair<string, double>(subject, grade));
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

double Student::getGrade(const string &subject) {
    if (grades.find(subject) == grades.end())
        throw out_of_range("No subject found!");
    return grades[subject];
}

void Student::computeAverage() {
    //if < 5
    double sum = 0.0;
    for (auto &grade: grades) {
        if (grade.second < 5) {
            return;
        } else {
            sum += grade.second;
        }
    }
    average = sum / grades.size();
}

double Student::getAverage() const {
    if (average >= 6) {
        return average;
    }
    return -1;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "Student " << student.id << endl;
    os << "First Name: " << student.getFirstName() << endl;
    os << "Last Name: " << student.getLastName() << endl;
    os << "\tSubjects and grades" << endl;
    for (auto &grades: student.grades) {
        os << "Subject: " << grades.first << endl;
        os << "Grade: " << grades.second << endl << endl;
    }
    if (student.getAverage() == -1) {
        os << "Not passed!\n";
    } else {
        os << "Average: " << student.getAverage() << endl;
    }
    os << endl;
    return os;
}

double Student::getAverageNoFail() const {
    return average;
}
