#include <iostream>
#include <set>

using namespace std;

int main() {

    set<int> val;
    set<int> val2{1, 2, 3, 4, 5};
    val.insert(34);
    val.insert(12);
    val.insert(44);
    for (const auto &temp: val) {
        cout << temp << endl;
    }
    //alapbol novekvo
    set<int, greater<int>> val3; //vagy siman greater<>
    val3.insert(3);
    val3.insert(11);
    for (auto &temp: val3) {
        cout << temp << endl;
    }
    val3.insert(11); //csak egy 11-es lehet benen
    for (auto &temp: val3) {
        cout << temp << endl;
    }
    set<int, greater<>>::iterator it;
    for (it = val3.begin(); it != val3.end(); it++) {
        cout << *it << " ";
    }

    set<int> setMasolt(val.begin(), val.end());
    //remove elements up to a given number
    cout << endl;
    cout << endl;
    for (auto &temp: setMasolt) {
        cout << temp << " ";
    }
    setMasolt.erase(setMasolt.begin(), setMasolt.find(34));
    cout << endl;
    for (auto &temp: setMasolt) {
        cout << temp << " ";
    }
    setMasolt.erase(setMasolt.find(34));
    cout << endl;
    for (auto &temp: setMasolt) {
        cout << temp << " ";
    }
    for (int i = 0; i < 19; ++i) {
        setMasolt.insert(i * 2);
    }
    cout << endl;
    for (auto &temp: setMasolt) {
        cout << temp << " ";
    }
    cout << "lower bound:" << *setMasolt.lower_bound(17) << endl;
    //setMasol.find(6) 1-et ad vissza ha benne van, 0-t ha nincs
    auto itt = setMasolt.find(2);
    if (itt != setMasolt.end()) {
        cout << "van";
    } else {
        cout << "nincs";
    }


    setMasolt.erase(setMasolt.find(6));
    cout << endl;
    for (auto &temp: setMasolt) {
        cout << temp << " ";
    }

    return 0;
}
