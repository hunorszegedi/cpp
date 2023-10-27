//
// Created by szege on 27/10/2023.
//

#include "QuizGame.h"
#include <iostream>

void QuizGame::run() {
    int numberOfQuestions = quiz.getNumberOfQuestions();
    for (int i = 0; i < numberOfQuestions; ++i) {
        const Question &currentQuestion = quiz.getQuestion(i);

        cout << currentQuestion.getText() << endl;

        const vector<Answer> &answers = currentQuestion.getAnswers();
        for (size_t j = 0; j < answers.size(); ++j) {
            cout << j + 1 << ". " << answers[j].getAnswer() << endl;
        }

        int userAnswer = getUserAnswer(currentQuestion);
        if (userAnswer < 1 || userAnswer > answers.size()) {
            cout << "Invalid answer" << endl;
            --i;
        } else {
            handleUserAnswer(currentQuestion, userAnswer);
        }
    }

    displayFinalScore();
}

int QuizGame::getUserAnswer(const Question &question) {
    int userAnswer;
    cout << "\nYour answer: ";
    cin >> userAnswer;
    return userAnswer;
}

void QuizGame::handleUserAnswer(const Question &question, int userAnswer) {
    const Answer &selectedAnswer = question.getAnswers()[userAnswer - 1];

    if (selectedAnswer.isCorrect()) {
        cout << "Correct!\n" << endl;
        score++;
    } else {
        displayCorrectAnswers(question);
    }
}

void QuizGame::displayCorrectAnswers(const Question &question) {
    cout << "Incorrect!" << endl;
    cout << "Correct answers: ";
    const vector<Answer> &answers = question.getAnswers();
    for (size_t j = 0; j < answers.size(); ++j) {
        if (answers[j].isCorrect()) {
            cout << j + 1 << " ";
        }
    }
    cout << "\n\n";
}

void QuizGame::displayFinalScore() {
    int totalQuestions = quiz.getNumberOfQuestions();
    cout << "\nYour score: " << score << "/" << totalQuestions << endl;
}
