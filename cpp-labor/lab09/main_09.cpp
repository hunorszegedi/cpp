#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

int main() {
    vector <string> fruits{
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };


    //1.
    cout << *find_if(fruits.begin(), fruits.end(), [](string fruit) {
        return fruit == "melon";
    }) << endl;

    //2.
    vector<int> array;
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    all_of(array.begin(), array.end(), [](int num) {
        return num % 2 == 0;
    });

    //3.
    for_each(array.begin(), array.end(), [&array](int num) {
        array[num] = num * 2;
    });
    for (auto num: array) {
        cout << num << " ";
    }

    //4.
    vector <string> months{
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    int counter = 0;
    cout << endl;
    for_each(months.begin(), months.end(), [&counter](string month) {
        if (month.length() > 5) {
            cout << month << " ";
            counter++;
        }
    });
    cout << endl << "Counter: " << counter << endl;

    return 0;
}