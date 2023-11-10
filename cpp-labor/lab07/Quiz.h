//
// Created by szege on 23/10/2023.
//

#ifndef LAB4_QUIZ_H
#define LAB4_QUIZ_H

#include <string>
#include <stdexcept>
#include "Question.h"

using namespace std;

class Quiz {
private:
    string name;
    vector<Question> questions;

    void readQuestions(const string &filename);

public:
    Quiz(const string &name, const string &filename) {
        this->name = name;
        readQuestions(filename);
    }

    string getName() const {
        return this->name;
    }

    vector<Question> getQuestions() const {
        return this->questions;
    }

    int getNumberOfQuestions() const {
        return questions.size();
    }

    const Question &getQuestion(int index) const {
        return questions[index];
    }
};


#endif //LAB4_QUIZ_H
