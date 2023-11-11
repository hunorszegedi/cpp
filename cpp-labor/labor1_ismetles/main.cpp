#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;


double calculateMean(const vector<double> &array) {
    double mean = 0.0;
    for (const auto &v: array) {
        mean += v;
    }
    return mean / array.size();
}

pair<double, double> biggestNumber(const vector<double> &array) {
    if (array.empty()) {
        return make_pair(NAN, NAN);
    }
    if (array.size() == 1) {
        return make_pair(array[0], array[0]);
    }
    double first = array[0];
    double second = array[0];
    for (const auto &v: array) {
        if (v > first) {
            second = first;
            first = v;
        } else if (v > second && v < first) {
            second = v;
        }
    }
    return make_pair(first, second);
}

vector<string> splitWords(const string &text) {
    vector<string> words;
    istringstream iss(text);
    string word;
    string removableChars = ".,:;!?";

    while (iss >> word) {
        string pushableWord;

        for (const auto &c: word) {
            if (isalpha(c)) {
                pushableWord.push_back(c);
            } else if (removableChars.find(c) == string::npos) {
                // Ha a karakter nem eltávolítható karakter, akkor is hozzáadjuk a szóhoz
                pushableWord.push_back(c);
            }
        }

        if (!pushableWord.empty()) {
            words.push_back(pushableWord);
        }
    }

    return words;
}

int countingWords(const string &text) {
    istringstream iss(text);
    string word;
    int wordCount = 0;
    while (iss >> word) {
        wordCount++;
    }
    return wordCount;
}

int main() {
//    vector<double> array;
//    cout << array.size() << endl;
//    for (int i = 0; i < 5; ++i) {
//        double value;
//        cin >> value;
//        array.push_back(value);
//    }
//    cout << array.size() << endl;
//    cout << "Mean: " << calculateMean(array);
//    pair<double, double> biggestNumbers = biggestNumber(array);
//    cout << endl << "First: " << biggestNumbers.first << endl << endl;
//    cout << endl << "Second: " << biggestNumbers.second << endl << endl;
//    istringstream input("1 2 joska 5 6");
//    string word;
//    while (input >> word) {
//        cout << word << endl;
//        istringstream wordstream(word);
//        double number;
//        if (wordstream >> number) {
//            cout << "number:" << number << endl;
//        } else {
//            cout << "word:" << word << endl;
//        }
//    }
//    string text = "alma korte a fa alatt";
//    cout << countingWords(text);
//    //toupper
//    //tolower
//    //getline
    string text2;
    getline(cin, text2);
    vector<string> kimenet = splitWords(text2);
    for (const auto &w: kimenet) {
        cout << w << endl;
    }
    for (auto &s: kimenet) {
        for (auto &c: s) {
            c = toupper(c);
        }
        cout << s << endl;
    }
    return 0;
}
