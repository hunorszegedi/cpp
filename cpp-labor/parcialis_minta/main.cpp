#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include <fstream>
#include "Library.h"

using namespace std;

//int main() {
//    vector<pair<string, vector<int>>> gyakorlo;
//    gyakorlo.reserve(5);
//
//    string line;
//    while (getline(cin, line) and !line.empty()) {
//        gyakorlo.emplace_back(line, vector<int>());
//    }
//
//    for (const auto &a: gyakorlo) {
//        cout << a.first << endl;
//        for (const auto &b: a.second) {
//            cout << b << " ";
//        }
//    }
//
//    for (int i = 0; i < gyakorlo.size(); ++i) {
//        int number;
//        cin >> number;
//        gyakorlo[i].second.push_back(number);
//        cin.ignore();  // Ez az újsor karakter beolvasásának eldobása
//    }
//
//    for (const auto &a: gyakorlo) {
//        cout << a.first << " ";
//        for (const auto &b: a.second) {
//            cout << b << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
int main() {
//    Library library(1);
//    Book b1("Jokai Mor", "Egri csillagok", 1980, 300);
//    library.addBook(b1);
//    ofstream output("kimenet.txt");
//    if (!output.is_open()) {
//        cerr << "HIBA" << endl;
//        exit(-1);
//    }
//    output << b1 << endl;
//    output.close();
//
//    Book b2("Jokai Mor", "A koszivu ember fiai", 1967, 400);
//    library.addBook(b2);
//    Book b3("Murakami Haruki", "Sotetedes utan", 2004, 250);
//    library.addBook(b3);
//    Book b4("Murakami Haruki", "A norveg erdo", 1987, 420);
//    library.addBook(b4);
//    Book b5("Murakami Haruki", "1Q84", 1987, 800);
//    library.addBook(b5);
//    Book b6("Knausgard Karl Ove", "Harcom", 2009, 1000);
//    library.addBook(b6);
//
//    library.printLibrary();
//
//    cout << "Find book: " << endl;
//    string line;
//    getline(cin, line);
//    cout << line;
//    try {
//        Book bFind = library.findBook(line);
//        bFind.printBook(cout);
//    } catch (out_of_range &e) {
//        cout << e.what() << endl;
//    }
//
//    cout << "Kinek a konyveit keresed?" << endl;
//    string line2;
//    getline(cin, line2);
//    library.countBooks(line2);
//
//    library.sortBooks();
//    library.printLibrary();
//
//    library.deleteGivenBook("Sotetedes utan");
//    library.printLibrary();
//
//    vector<int> v = {1, 2, 3, 4};
//    v.erase(v.begin() + 2);
}