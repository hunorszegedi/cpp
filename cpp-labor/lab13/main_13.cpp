#include <iostream>

#include "SimpleTextGenerator.h"

int main() {

    string text = "Now is not the time for sleep, now is the time for party!";
    SimpleTextGenerator generator;
//    generator.trainFromText(text);
//    generator.printData();
    generator.trainFromFile("input.txt");
    generator.printData();
    for (int i = 0; i < 10; ++i) {
        cout << generator.generate("zangalewa world", 9) << endl;
    }
//    for (int i = 0; i < 5; ++i) {
//        cout << "Generated text: " << generator.generate("now is", 6) << endl;
//    }

    return 0;
}