//
// Created by szege on 23/10/2023.
//

#ifndef LAB4_ANSWER_H
#define LAB4_ANSWER_H

#include <string>

using namespace std;

class Answer {
private:
    string answer;
    bool correct;

public:
    Answer(string answer = "", bool correct = false) :
            answer(answer), correct(correct) {

    }

//    void setAnswer(const string answer) {
//        this->answer = answer;
//    }

    void setCorrect(bool correct) {
        this->correct = correct;
    }

    const string &getAnswer() const {
        return answer;
    }

    void setAnswer(const string &answer) {
        Answer::answer = answer;
    }

//    const string &getAnswer() const {
//        return answer;
//    }

    bool isCorrect() const {
        return correct;
    }

//    ~Answer(); destruktor

};

#endif //LAB4_ANSWER_H
