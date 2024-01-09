#include "Base.h"
#include "Derived.h"

#include <iostream>

class MyClass {
public:
    MyClass() {
        cout << "Konstruktor hivasa" << endl;
    }

    void printMessage() {
        std::cout << "MyClass objektum letrehozva." << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass objektum megsemmisult." << std::endl;
    }
};

int main() {

    MyClass *obj = new MyClass;

    delete obj;

    MyClass *obj2 = new MyClass ; // memoriaszivargas, mert nem szabaditjuk fel manualisan

    return 0;
}
