#include <iostream>
#include "Array.h"

int main() {
    Array a1;
    cout << a1.getMSize() << endl;
    cin >> a1;
    Array a2(5);
    cin >> a2;
    cout << a1 << endl;
    cout << a2 << endl;
    Array a3(a2);
    Array a4 = *new Array;
    cout << a1.getMSize() << endl;
    return 0;
}
