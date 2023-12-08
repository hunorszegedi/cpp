#include <iostream>
#include "GraduationDao.h"
#include "StudentService.h"
#include "StudentServiceImpl.h"

using namespace std;

int main() {
//    Student student(1, "Nagy", "Elemer");
//    //1
//    cout << student.getId() << endl;
//    //2
//    student.setId(2);
//    cout << student.getId() << endl;
//    //3
//    cout << student.getFirstName() << " " << student.getLastName() << endl;
//    //4
//    student.addGrade("Matek", 6);
//    student.addGrade("Roman", 4);
//    student.addGrade("Magyar", 6);
//    //5
//    cout << student.getGrade("Matek") << endl;
////    cout << student.getGrade("Foldrajz") << endl;
//    //6
//    for (auto &grades: student.getGrades()) {
//        cout << grades.first << ": " << grades.second << endl;
//    }
//    //7
//    cout << endl;
//    //8
//    student.computeAverage();
//    //9
//    cout << student;


    //GRADDao
//    GraduationDao graduationDao(2024);
//    graduationDao.enrollStudents("names.txt");
//
//    graduationDao.saveGradesForSubject("Roman", "romanian.txt");
//    graduationDao.saveGradesForSubject("Magyar", "hungarian.txt");
//    graduationDao.saveGradesForSubject("Matek", "math.txt");
//
//    for (pair<int, Student> student: graduationDao.getStudents()) {
//        student.second.computeAverage();
////        cout << student.first << endl;
////        cout << student.second << endl;
////        cout << endl;
//    }
//
//    cout << "Num enrolled: " << graduationDao.numEnrolled() << endl;
//    graduationDao.computeAverage();
//    cout << "Passed: " << graduationDao.numPassed() << endl;
//
//    cout << "Matek: " << graduationDao.getAverageBySubject("Matek") << endl;
//    cout << "Magyar: " << graduationDao.getAverageBySubject("Magyar") << endl;
//    cout << "Roman: " << graduationDao.getAverageBySubject("Roman") << endl;

    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    string subjectsFirst[] = {"romanian", "hungarian", "math"};
    int numSubjects = sizeof(subjectsFirst) / sizeof(subjectsFirst[0]);
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
        dao.saveGradesForSubject(subjectsFirst[i], subjectsFirst[i] + ".txt");
    }
    dao.computeAverage();
    cout << "Number of passed students: " << dao.numPassed() << endl;
    cout << "Average grade for math: " << dao.getAverageBySubject("math") << endl;
    cout << "Average grade for hungarian: " << dao.getAverageBySubject("hungarian") << endl;
    cout << "Average grade for romanian: " << dao.getAverageBySubject("romanian") << endl;

    //
    cout << endl << endl;

    StudentService *service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1) {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;
        if (id == -1) {
            break;
        }
        if (!service->isEnrolled(id)) {
            cout << "Student id=" << id << " not found" << endl;
            continue;
        }
        cout << "Student id=" << id << " results: " << endl;
        bool passed = service->isPassed(id);
        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;
        if (!passed) {
            continue;
        }
        vector<string> subjects = service->getSubjects(id);
        for (int i = 0; i < subjects.size(); ++i) {
            cout << "\t" << subjects[i] << ": " <<
                 service->getResultBySubject(id, subjects[i]) << endl;
        }
        cout << "\taverage: " << service->getAverage(id) << endl;
    }
    delete service;//
    return 0;
}