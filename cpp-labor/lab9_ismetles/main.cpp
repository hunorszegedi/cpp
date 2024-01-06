#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<string> nevek;
//    vector<string>neve2{"josk","asd"};
    nevek.push_back("Joska");
    nevek.push_back("Anna");
    nevek.push_back("Bela");
    nevek.push_back("Abel");
    //find if
    cout << *find_if(nevek.begin(), nevek.end(), [](const string &nev) {
        return nev == "Anna";
    });

    vector<int> valami;
    for (int i = 0; i < 10; ++i) {
        valami.push_back(i * 2);
    }
    cout << endl;
    bool areOrNot = all_of(valami.begin(), valami.end(), [](int num) {
        return num % 2 == 0;
    });
    if (areOrNot) {
        cout << "mind az";
    } else {
        cout << "nem";
    }
    cout << endl;
    for (const auto &temp: valami) {
        cout << temp << " ";
    }
    vector<int> nemtudom;
    for (int i = 0; i < 9; ++i) {
        nemtudom.push_back(i);
    }
    cout << endl << endl;
    for (const auto &temp: nemtudom) {
        cout << temp << " ";
    }
    for_each(valami.begin(), valami.end(), [&nemtudom](int &num) {
        nemtudom[num / 2] = num;
        num = num * 3;
    });
    cout << endl << endl;
    for (const auto &temp: nemtudom) {
        cout << temp << " ";
    }
    cout << endl;
    for (const auto &temp: valami) {
        cout << temp << " ";
    }

    cout << endl << endl;
    vector<string> dolgok{"kutya", "macska", "kalapacs", "szo", "ceruza", "kes", "va"};
    int counter = 0;
    for_each(dolgok.begin(), dolgok.end(), [&counter](const string &szo) {
        if (szo.length() <= 3) {
            counter++;
        }
    });
    cout << counter;
    cout << endl;
    vector<int> temp;
    srand(time(nullptr));
    for (int i = 0; i < 20; ++i) {
        temp.push_back(rand() % 10);
    }
    for (const auto &v: temp) {
        cout << v << " ";
    }
    sort(temp.begin(), temp.end(), [](int a, int b) {
        return a > b;
    });
    cout << endl;
    for (const auto &v: temp) {
        cout << v << " ";
    }
    sort(temp.begin(), temp.end(), less<>());
    cout << endl;
    for (const auto &v: temp) {
        cout << v << " ";
    }
    vector<pair<string, double>> atlagHoH;
    atlagHoH.push_back(make_pair("Januar", -10));
    atlagHoH.push_back(make_pair("Februar", -11));
    atlagHoH.push_back(make_pair("Marcius", 4));
    atlagHoH.push_back(make_pair("Aprilis", 3));
    cout << endl;
    sort(atlagHoH.begin(), atlagHoH.end(), [](const pair<string, int> &temp1, const pair<string, int> &temp2) {
        return temp1.second > temp2.second;
    });
    for (const auto &h: atlagHoH) {
        cout << "Honap : " << h.first << "Homerseklet: " << h.second << endl;
    }
    sort(temp.begin(), temp.end(), [](int num1, int num2) {
        return abs(num1) > abs(num2);
    });
    for_each(atlagHoH.begin(), atlagHoH.end(), [](pair<string, double> &honho) {
        honho.first[0] = tolower(honho.first[0]);
    });
    for (const auto &h: atlagHoH) {
        cout << "Honap : " << h.first << "Homerseklet: " << h.second << endl;
    }

    vector<char> angolAbeces = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    shuffle(angolAbeces.begin(), angolAbeces.end(), std::mt19937(std::random_device()()));
    return 0;

}
