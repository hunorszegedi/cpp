#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> mp;
    mp["alma"] = 1;
    mp["korte"] = 2;
    mp["dio"] = 3;
    map<string, int>::iterator it = mp.begin(); //vagy auto it
    //get the iterator poiting to the first element in the map

    while (it != mp.end()) {
        cout << "Key: " << it->first
             << ", Value: " << it->second
             << endl;
        ++it;
    }

    cout << "mp size: " << mp.size() << endl;

    mp.insert(pair<string, int>("ananasz", 90));
    mp.insert(pair<string, int>("kaposzta", 199));


    cout << "mp size: " << mp.size() << endl;

    for (const auto &temp: mp) {
        cout << "Key: " << temp.first << ",Value: " << temp.second << endl;
    }

    mp["giliszta"] = 100;
    cout << "mp size: " << mp.size() << endl;

    map<string, int>::iterator it2;
    for (it2 = mp.begin(); it2 != mp.end(); it2++) {
        cout << "Key: " << it2->first << ", Value: " << it2->second << endl;
    }
    cout << endl;

    map<string, int> mp2(mp.begin(), mp.end());
    for (const auto &temp2: mp2) {
        cout << "Key: " << temp2.first << ", Value: " << temp2.second << endl;
    }

    cout << endl;
    //remove elements with a given key
//    mp2.erase(mp2.begin(), mp2.find("kaposzta")); // mindent eltavolit egeszen eddig a kulcsig
    for (const auto &temp2: mp2) {
        cout << "Key: " << temp2.first << ", Value: " << temp2.second << endl;
    }
    cout << endl;

    mp2.erase("dio");
    //int num = mp2.erase("dio") az eltavolitott elemek szama
    for (const auto &temp2: mp2) {
        cout << "Key: " << temp2.first << ", Value: " << temp2.second << endl;
    }

    map<int, int> ujMap;
    srand(time(0));
    ujMap[1] = 10;
    ujMap[2] = 20;
    ujMap.insert(pair<int, int>(3, 30));
    for (int i = 4; i < 20; ++i) {
        ujMap.insert(pair<int, int>(i, i * 10));
    }
    for (const auto &temp3: ujMap) {
        cout << "Key: " << temp3.first << ", Value: " << temp3.second << endl;
    }
    cout << endl;
    ujMap.erase(ujMap.begin(), ujMap.find(13));
    ujMap.erase(15);
    for (const auto &temp3: ujMap) {
        cout << "Key: " << temp3.first << ", Value: " << temp3.second << endl;
    }

    cout << endl;
    // lower bound and upper bound for map gquiz1 key = 5
    //x kulcsnal nagyobb elso elem
    //ha megegyezik egy letezo kulccsal, akkor az adott kulcsu elemre mutato iteratort adja vissza
    cout << ujMap.lower_bound(12)->second << endl;

    cout << endl;
    //ertek kiiratasa
    cout << ujMap[18] << endl;

    //check if a key isin the map
    cout << endl;
    if (ujMap.count(20) > 0) {
        cout << "benne van" << endl;
    } else {
        cout << "nincs benne" << endl;
    }

    //find an element with a given key
    cout << endl;
    auto it3 = ujMap.find(18);
    if (it3 != ujMap.end()) {
        cout << "Key: " << it3->first << ", Value: " << it3->second << endl;
    } else {
        cout << "nincs ilyen kulcs" << endl;
    }

    map<string, int> mp3;
    mp3.insert(pair<string, int>("en", 2));
    mp3.insert(pair<string, int>("te", 2));
    mp3.insert(pair<string, int>("o", 2));
    mp3.insert(pair<string, int>("mi", 2));
    mp3.insert(pair<string, int>("ti", 2));
    mp3.insert(pair<string, int>("ok", 2));
    for (const auto &temp: mp3) {
        cout << temp.first << " " << temp.second << endl;
    }
    mp3.erase(mp3.begin(), mp3.find("ok"));
    cout << endl;
    for (const auto &temp: mp3) {
        cout << temp.first << " " << temp.second << endl;
    }
    return 0;
}
