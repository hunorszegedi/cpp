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
    void setText(const string &textP) {
        this->text = textP;
    }

    void setAnswers(const vector<Answer> &answersP) {
        this->answers = answersP;
    }

    string getText() const {
        return text;
    }

    vector<Answer> getAnswers() const {
        return answers;
    }

    double getNumberOfCorrectAnswers() {
        double numberOfCorrectAnswers = 0;
        for (const auto &answer: answers) {
            if (answer.isCorrect()) {
                numberOfCorrectAnswers++;
            }
        }
        return numberOfCorrectAnswers;
    }
};

#endif //LAB4_QUESTION_H
