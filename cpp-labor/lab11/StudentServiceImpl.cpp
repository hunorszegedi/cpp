//
// Created by szege on 08/12/2023.
//

#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    return dao->findById(id).getId() == id;
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string> subjects;
    for (const auto &grade: dao->findById(id).getGrades()) {
        subjects.push_back(grade.first);
    }
    return subjects;
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    return dao->findById(id).getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    return dao->findById(id).getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    return dao->findById(id).getAverage() >= 6;
}
