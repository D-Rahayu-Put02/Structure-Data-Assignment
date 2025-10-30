#include "singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;
    CreateList(L);

    // Alokasi node
    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi Linked List Awal: ";
    printInfo(L);

    // Hapus node 9 (deleteFirst)
    deleteFirst(L);
    // Hapus node 2 (deleteLast)
    deleteLast(L);
    // Hapus node 8 (deleteAfter)
    address Prec = L.first->next; // node setelah 12 (yaitu 8)
    deleteAfter(L, Prec);

    cout << "Isi Linked List Setelah Delete: ";
    printInfo(L);

    cout << "Jumlah node: " << nbList(L) << endl;

    // Hapus semua node
    deleteList(L);
    cout << "List setelah deleteList(): ";
    printInfo(L);
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}
