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
    int id, grade;
    while (file >> id >> grade) {
        if (students.find(id) == students.end()) {
            cerr << "Student not found!\n" << id << endl;
            exit(2);
        }
        students.find(id)->second.addGrade(subject, grade);
    }
}

void GraduationDao::computeAverage() {

}

int GraduationDao::numEnrolled() const {
    return 0;
}

int GraduationDao::numPassed() const {
    return 0;
}

//Student GraduationDao::findById(int id) const {
////    return Student(0, __cxx11::basic_string(), __cxx11::basic_string());
//}

double GraduationDao::getAverageBySubject(const string &subject) const {
    return 0;
}

const map<int, Student> &GraduationDao::getStudents() const {
    return students;
}

Student GraduationDao::findById(int id) const {

}
