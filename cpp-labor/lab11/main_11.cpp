#include <iostream>
#include "Student.h"
#include "GraduationDao.h"

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
    GraduationDao graduationDao(2024);
    graduationDao.enrollStudents("names.txt");

    graduationDao.saveGradesForSubject("Roman", "romanian.txt");
    graduationDao.saveGradesForSubject("Magyar", "hungarian.txt");
    graduationDao.saveGradesForSubject("Matek", "math.txt");

    for (const auto &studentTemp: graduationDao.getStudents()) {
        cout << studentTemp.first << endl;
        cout << studentTemp.second << endl;
        cout << endl;
    }

    return 0;
}