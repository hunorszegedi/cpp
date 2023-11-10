//
// Created by szege on 27/10/2023.
//

#include "QuizGame.h"
#include <iostream>

void QuizGame::play() {
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

    cout << "Your final score: " << getScore() << endl;
    user.addScore(quiz.getName(), getScore()); // Assuming Quiz has a method getName() to get the quiz name.
    cout << "Score added to user " << user.getName() << " for quiz " << quiz.getName() << ": " << getScore() << endl;
}

int QuizGame::getUserAnswer(const Question &question) {
    int userAnswer;
    cout << "Enter your answer (1-" << question.getAnswers().size() << "): ";
    cin >> userAnswer;
    return userAnswer;
}

void QuizGame::handleUserAnswer(Question question, int userAnswer) {
    const vector<Answer> &answers = question.getAnswers();
    if (answers[userAnswer - 1].isCorrect()) {
        cout << "Correct!" << endl;
        score += 1.0 / question.getNumberOfCorrectAnswers();
    } else {
        cout << "Incorrect!" << endl;
    }
}

