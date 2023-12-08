#include <iostream>

using namespace std;

#include <random>
#include <vector>
#include <algorithm>

int main() {
    vector<string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };


    //1.
    cout << "1." << endl;
    cout << *find_if(fruits.begin(), fruits.end(), [](string fruit) {
        return fruit == "melon";
    }) << endl;

    //2.
    cout << endl << "2." << endl;
    vector<int> array;
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    bool isOrNot = all_of(array.begin(), array.end(), [](int num) {
        return num % 2 == 0;
    });
    if (isOrNot) {
        cout << "All numbers are even." << endl;
    } else {
        cout << "Not all numbers are even." << endl;
    }

    //3.
    cout << endl << "3." << endl;
    for_each(array.begin(), array.end(), [&array](int num) {
        array[num] = num * 2;
    });
    for (auto num: array) {
        cout << num << " ";
    }

    //4.
    cout << endl << endl << "4.";
    vector<string> months{
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    int counter = 0;
    cout << endl;
    for_each(months.begin(), months.end(), [&counter](string month) {
        if (month.length() == 5) {
            cout << month << " ";
            counter++;
        }
    });
    cout << endl << "Counter: " << counter << endl;

    //5
    cout << endl << "5." << endl;
    vector<double> nums = {3, 9, 12, 1, 150, 3.1, 4.5, 0};
    sort(nums.begin(), nums.end(), [](double num1, double num2) {
        return num1 > num2;
    });
    //lambda
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl << endl;
    //greater
    sort(nums.begin(), nums.end(), greater<double>());
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl << endl;

    //6
    cout << "6." << endl;
    vector<pair<string, int>> pairs;
    for (const auto &a: months) {
        pairs.emplace_back(a, rand() % (30 - (-10) + 1) + (-10));
    }
    for (auto pair: pairs) {
        cout << pair.first << " " << pair.second << endl;
    }
    sort(pairs.begin(), pairs.end(), [](pair<string, int> pair1, pair<string, int> pair2) {
        return pair1.second < pair2.second;
    });
    cout << endl;
    for (auto pair: pairs) {
        cout << pair.first << " " << pair.second << endl;
    }

    //7
    cout << endl << "7." << endl;
    vector<double> nums2 = {3, 9, 12, 1, 150, 3.1, 4.5, 0, -3, -9, 133, -90};
    sort(nums2.begin(), nums2.end(), [](double num1, double num2) {
        return abs(num1) < abs(num2);
    });
    for (auto num: nums2) {
        cout << num << " ";
    }
    cout << endl;

    //8
    cout << endl << "8." << endl;
    for (auto &month: months) {
        transform(month.begin(), month.end(), month.begin(), ::tolower);
    }
    cout << "Month names with lowercase: " << endl;
    for (const auto &month: months) {
        cout << month << " ";
    }

    //9
    cout << endl << endl << "9." << endl;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    shuffle(alphabet.begin(), alphabet.end(), std::mt19937(std::random_device()()));
    cout << "Kevert: " << alphabet << endl;

    sort(months.begin(), months.end(), [&alphabet](const string &month1, const string &month2) {
        return alphabet.find(month1[0]) < alphabet.find(month2[0]);
    });
    cout << "Rendezett: " << endl;
    for (const auto &month: months) {
        cout << month << " ";
    }

    return 0;
}