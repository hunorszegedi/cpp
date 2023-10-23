#include <iostream>
#include "Quiz.h"

int main() {
    Quiz quiz("Quiz", "quiz.txt");//jo lenne itt egy olyan konstruktor, amivel nevet adhatunk 2 parameteres
    cout << quiz.getName() << endl;
    cout << quiz.getNumberOfQuestions() << endl;
    int num_questions = quiz.getNumberOfQuestions();
    for (int i = 0; i < num_questions; i++) {
        auto &question = quiz.getQuestion(i);
        cout << (i + 1) << ". " << question.getText() << endl;
        cout << "Pick the correct answer(s)!" << endl;
        for (int j = 0; j < question.getAnswers().size(); ++j) {
            cout << "\t" << question.getAnswers()[j].getAnswer() << endl;
        }
    }
    return 0;
}