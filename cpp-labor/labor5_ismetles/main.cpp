#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readFile(const string &fileName) {
    int counter = 0;
    vector<pair<string, vector<string>>> kerdesekValaszok;
    vector<pair<int, string>> helyesValaszok;
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Hiba!" << endl;
        exit(-1);
    }
    string line;
    while (getline(file, line)) {
        switch (line[0]) {
            case 'Q':
                cout << "Ez egy kerdes: " << line.substr(2) << endl;
                kerdesekValaszok.emplace_back(line.substr(2), vector<string>());
                break;
            case 'A':
                cout << "Ez egy valasz: " << line.substr(2) << endl;
                kerdesekValaszok.back().second.push_back(line.substr(2));
                break;
            default:
                if (isdigit(line[0])) {
                    cout << "Ez egy szam" << line << endl;
                    helyesValaszok.emplace_back(counter, line);
                    counter++;
                }
                break;
        }
        cout << line << endl;
    }
    for (const auto &a: kerdesekValaszok) {
        cout << a.first << endl;
        for (const auto &b: a.second) {
            cout << b << endl;
        }
    }
    for (const auto &a: helyesValaszok) {
        cout << " - " << a.first << " - " << a.second << endl;
    }
    file.close();
}

int main() {
    ofstream outputFile("kimenet.txt");
    if (outputFile.is_open()) {
        outputFile << "Hello world!" << endl;
        outputFile.close();
    } else {
        cout << "Nem sikerult megnyitni a fajlt!" << endl;
    }
    readFile("quiz.txt");
    return 0;
}
