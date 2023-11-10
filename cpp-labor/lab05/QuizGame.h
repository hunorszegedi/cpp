//
// Created by szege on 27/10/2023.
//

#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H

#include "Quiz.h"

class QuizGame {
private:
    Quiz quiz;
    int score;

public:
    QuizGame(const Quiz &quiz, int score) : quiz(quiz), score(0) {}

    void run();

    static int getUserAnswer(const Question &question);

    void handleUserAnswer(Question question, int userAnswer);

    static void displayCorrectAnswers(const Question &question);

    void displayFinalScore();
};

#endif //LAB5_QUIZGAME_H
