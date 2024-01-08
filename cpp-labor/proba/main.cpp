#include "Zeneszek.h"

int main() {
    Zeneszek zeneszek("input.txt");
    zeneszek.listazas();
    cout << zeneszek.legtobbHangszer();
    zeneszek.bennevan("Jano");
    return 0;
}
