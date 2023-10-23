//
// Created by szege on 23/10/2023.
//

#ifndef LAB4_QUESTION_H
#define LAB4_QUESTION_H

#include <string>
#include <vector>
#include "Answer.h"

using namespace std;


class Question {
private:
    string text;
    vector<Answer> answers;

public:
    Question() = default; //nem irok semmit, a fordito csinalja // default konstruktor
    void setText(const string &text) {
        this->text = text;
    }

    void setAnswers(const vector<Answer> &answers) {
        this->answers = answers;
    }

    string getText() const {
        return text;
    }

    vector<Answer> getAnswers() const {
        return answers;
    }
};

#endif //LAB4_QUESTION_H
