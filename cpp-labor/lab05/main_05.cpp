#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

int main() {
//    Quiz quiz("Quiz", "quiz.txt");//jo lenne itt egy olyan konstruktor, amivel nevet adhatunk 2 parameteres
//    cout << quiz.getName() << endl;
//    cout << quiz.getNumberOfQuestions() << endl;
//    int num_questions = quiz.getNumberOfQuestions();
//    for (int i = 0; i < num_questions; i++) {
//        auto &question = quiz.getQuestion(i);
//        cout << (i + 1) << ". " << question.getText() << endl;
//        cout << "Pick the correct answer(s)!" << endl;
//        for (int j = 0; j < question.getAnswers().size(); ++j) {
//            cout << "\t" << question.getAnswers()[j].getAnswer() << endl;
//        }
//    }

    Quiz quiz("Kviz", "quiz.txt");

    cout << "Kviz neve: " << quiz.getName() << endl;
    vector<Question> questions = quiz.getQuestions();

    for (size_t i = 0; i < questions.size(); ++i) {
        cout << "Kerdes " << (i + 1) << ": " << questions[i].getText() << endl;

        vector<Answer> answers = questions[i].getAnswers();
        for (size_t j = 0; j < answers.size(); ++j) {
            cout << "  " << (j + 1) << ". " << answers[j].getAnswer() << " ("
                 << (answers[j].isCorrect() ? "Helyes" : "Nem helyes") << ")" << endl;
        }

        cout << "Helyes valaszok: ";
        for (size_t j = 0; j < answers.size(); ++j) {
            if (answers[j].isCorrect()) {
                cout << (j + 1) << " ";
            }
        }
        cout << endl;
    }

    QuizGame quizGame(quiz, 0);
    quizGame.run();

    return 0;
}