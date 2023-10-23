//
// Created by szege on 23/10/2023.
//

#include "Quiz.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void Quiz::readQuestions(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "File not found: " << filename << endl;
        exit(1);
    }

    string line;
    Question question;
    vector<Answer> answers;
    while (getline(file, line)) {
        switch (line[0]) {
            case 'Q':
                question.setText(line.substr(2)); //Q es a szokoz miatt
                answers.clear();
                break;
            case 'A': {
                answers.emplace_back(line.substr(2)); //A es a szokoz miatt
                break;
            }
            default:
                istringstream iss(line); //stringbol streamet csinal, hogy tudjuk szetbontani
                int index;
                while (iss >> index) {
                    answers[index - 1].setCorrect(true); //0-tol van a vektorban az indexeles
                }
                question.setAnswers(answers);
                questions.push_back(question);
                break;
        }
    }
    file.close();
}


