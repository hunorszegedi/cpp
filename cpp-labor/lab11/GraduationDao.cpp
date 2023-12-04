//
// Created by szege on 04/12/2023.
//

#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "File Not Found!\n" << filename << endl;
        exit(1);
    }
//    string line;
//    while (getline(file, line)) {
//        istringstream iss(line);
//        int id;
//        string firstName, lastName;
//        iss >> id >> firstName >> lastName;
//        Student student(id, firstName, lastName);
//        this->students.insert(pair<int, Student>(id, student));
//    }
    int id;
    string firstName, lastName;
    while (file >> id >> firstName >> lastName) {
        Student student(id, firstName, lastName);
        this->students.insert(pair<int, Student>(id, student));
    }
    file.close();
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "File Not Found!\n" << filename << endl;
        exit(1);
    }
    int id;
    double grade;
    while (file >> id >> grade) {
        if (students.find(id) == students.end()) {
            cerr << "Student not found!\n" << id << endl;
            exit(2);
        }
        students.find(id)->second.addGrade(subject, grade);
    }
}

void GraduationDao::computeAverage() {
    double average = 0;
    for (auto &student: students) {
        student.second.computeAverage();
        if (student.second.getAverage() >= 6) {
            average += student.second.getAverage();
        } else {
            average += student.second.getAverageNoFail();
        }
//        cout << student.second.getAverageNoFail() << endl;
    }
    average /= students.size();
    cout << "Average: " << average << endl;
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;
    for (auto &student: students) {
        if (student.second.getAverage() >= 6) {
            count++;
        }
    }
    return count;
}

Student GraduationDao::findById(int id) const {
    if (students.find(id) == students.end()) {
        throw out_of_range("Student not found!");
    }
    return students.find(id)->second;
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double average = 0;
    int count = 0;
    for (auto &student: students) {
        if (student.second.getGrades().find(subject) != student.second.getGrades().end()) {
            average += student.second.getGrades().find(subject)->second;
            count++;
        }
    }
    average /= count;
    return average;
}

const map<int, Student> &GraduationDao::getStudents() const {
    return students;
}
