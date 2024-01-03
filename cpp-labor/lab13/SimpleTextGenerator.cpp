//
// Created by szege on 18/12/2023.
//

#include <sstream>
#include <iostream>
#include <fstream>
#include "SimpleTextGenerator.h"
#include <algorithm>

void SimpleTextGenerator::trainFromText(string trainingText) {
    istringstream iss(trainingText);
    string word;
    vector<string> words;

    while (iss >> word) {
        for (int i = 0; i < word.length(); i++) {
            if (ispunct(word[i])) //ispunct() igazat ad vissza, ha irasjelrol van szo
                word.erase(i--, 1);
            else {
                word[i] = tolower(word[i]);
            }
        }
        words.push_back(word);
    }


    for (int i = 0; i < words.size(); i++) {
        string prefix = words[i] + " " + words[i + 1];
        string postfix = words[i + 2];
        data[prefix].push_back(postfix);
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);
    string line;
    string word;
    vector<string> words;

    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> word) {
            for (int i = 0; i < word.length(); i++) {
                if (ispunct(word[i]))
                    word.erase(i--, 1);
                else {
                    word[i] = tolower(word[i]);
                }
            }
            words.push_back(word);
        }
    }

    for (int i = 0; i < words.size(); i++) {
        string prefix = words[i] + " " + words[i + 1];
        string postfix = words[i + 2];
        //megnezni, ha benne van-e mar
        data[prefix].push_back(postfix);
    }

}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    string result;
    result += startWords;

    for (int i = 0; i < numWords; ++i) {
        string prefix = startWords;
        if (data.find(prefix) != data.end() && !data[prefix].empty()) {
            int randomIndex = rand() % data[prefix].size();
            string randomPostfix = data[prefix][randomIndex];
            result += " " + randomPostfix;
            startWords = startWords.substr(startWords.find(" ") + 1) + " " + randomPostfix;
        } else {
            break;
        }
    }

    return result;
}

void SimpleTextGenerator::printData() {
    for (const auto &i: data) {
        cout << i.first << " | ";
        cout << "{ ";
        for (auto &j: i.second) {
            cout << j << ", ";
        }
        cout << "}";
        cout << endl;
    }
}
