#include <iostream>
#include <fstream>
#include "Book.h"

int main() {

    Book book1("Aladar", "Ket almafa", 2000, 190);
    cout << book1 << endl;
    Book myBook("John Doe", "C++ Programming", 2022, 500);
    ofstream outputFile("kimenet.txt");
    if (outputFile.is_open()) {
        outputFile << myBook;
        outputFile.close();
    } else {
        cerr << "File could not open!\n" << endl;
    }

    Book b1;
    cin >> b1;
    cout << b1;

    return 0;
}
