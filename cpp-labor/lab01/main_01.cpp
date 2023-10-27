#include <fstream>
#include <map>
#include "functions.h"

/*
int main(int argc, char *argv[])
{

    double sum = 0;
    for (int i = 0; i < argc; ++i) {
        istringstream iss(argv[i]);
        double value = 0;
        iss >> value;
        if (!iss) {
            cerr << "Invalid argument: " << argv[i] << endl;
        } else {
            sum += value;
        }
    }
    cout << sum << endl;


}
*/

int main(int argc, char *argv[]) {

    //1.
    cout << "Give me a number:" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "The number of bits in " << i << " is " << countBitsOfAPositiveNumber(i) << endl;
    }
    //2.
    for (int i = 0; i < 35; ++i) {
        int m = 0;
        if (setBit(m, i)) {
            cout << i << " ---> " << m << endl;
        } else {
            cout << "Impossible operation!" << endl;
        }
    }
    //3.
    double elements[] = {1.0, 2.0, 9.0, 4.0, 5.0};
    int numElements = sizeof(elements) / sizeof(elements[0]);
    double result = mean(elements, numElements);
    if (!isnan(result)) {
        cout << "Az atlag: " << result << endl;
    } else {
        cout << "Az adatok nem ervenyesek (ures tomb)!" << endl;
    }
    //4.
    double result2 = stddev(elements, numElements);
    if (!isnan(result2)) {
        cout << "Az atlag: " << result2 << endl;
    } else {
        cout << "Az adatok nem ervenyesek (ures tomb)!" << endl;
    }
    //5.
    double numbers2[] = {1.0, 12.0, 3.0, 42.0, 2.0};
    int numElements2 = sizeof(numbers2) / sizeof(numbers2[0]);

    pair<double, double> result1 = max2(numbers2, numElements2);

    cout << "A ket legnagyobb elem: " << result1.first << " es " << result1.second << endl;

    //6. karakter
    double sum = 0;
    for (int i = 1; i < argc; ++i) {
        istringstream iss(argv[i]);
        double number = 0;
        if (iss >> number) {
            sum += number;
        }
    }
    cout << "Az osszeg: " << sum << endl;

    //7. karakter
    string text = "Ez egy pelda szoveg, amit szavakra fogunk bontani.";
    int result3 = countWords(text);

    cout << "A szavak szama: " << result3 << endl;

    //8. karakter
    string originalText = "Hello, World! 123";
    string encodedText = code(originalText);
    string decodedText = decode(encodedText);

    cout << "Eredeti szoveg: " << originalText << endl;
    cout << "Kodolt szoveg: " << encodedText << endl;
    cout << "Dekodolt szoveg: " << decodedText << endl;

    //9. karakter
    string line;

    while (getline(cin, line)) {
        if (line == "STOP") {
            break;
        }
        string capitalized = capitalizeWords(line);
        cout << capitalized << endl;
    }

    //EXTRA
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <text_file> <n>" << endl;
        return -1;
    }

    string fileName = argv[1];
    int m = stoi(argv[2]);

    ifstream file(fileName);
    if (!file) {
        cerr << "Error: File not found!" << endl;
        return -2;
    }

    map<string, int> wordFrequency;

    string lineExtra;
    while (getline(file, lineExtra)) {
        vector<string> words = splitWords(lineExtra);
        for (const string &word: words) {
            wordFrequency[word]++;
        }
    }

    vector<pair<string, int>> sortedWords(wordFrequency.begin(), wordFrequency.end());
    sort(sortedWords.begin(), sortedWords.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second > b.second;
    });

    cout << m << " most common words:" << endl;
    for (int i = 0; i < m && i < sortedWords.size(); i++) {
        cout << sortedWords[i].first << ": " << sortedWords[i].second << endl;
    }

    return 0;
}