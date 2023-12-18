//
// Created by szege on 18/12/2023.
//

#ifndef LAB13_SIMPLETEXTGENERATOR_H
#define LAB13_SIMPLETEXTGENERATOR_H


#include "TextGenerator.h"
#include <map>
#include <vector>

class SimpleTextGenerator : public TextGenerator {
    map <string, vector<string>> data;

public:
    virtual void trainFromFile(string filename) override;

    virtual string generate(string startWords, int numWords = 6) override;

    ~SimpleTextGenerator() override = default;

    virtual void trainFromText(string trainingText) override;

    void printData();
};

#endif //LAB13_SIMPLETEXTGENERATOR_H
