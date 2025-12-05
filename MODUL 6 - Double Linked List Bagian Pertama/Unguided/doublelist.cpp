#include "doublelist.h"

void CreateList(List &L) {
    L.first = NIL;
    L.last = NIL;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NIL;
    P->prev = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

void insertLast(List &L, address P) {
    if (L.first == NIL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NIL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.tahunbuat << endl;
        cout << endl;
        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NIL) {
        if (P->info.nopol == nopol) return P;
        P = P->next;
    }
    return NIL;
}

void deleteFirst(List &L) {
    if (L.first != NIL) {
        address P = L.first;

        if (L.first == L.last) {
            L.first = L.last = NIL;
        } else {
            L.first = P->next;
            L.first->prev = NIL;
        }
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != NIL) {
        address P = L.last;

        if (L.first == L.last) {
            L.first = L.last = NIL;
        } else {
            L.last = P->prev;
            L.last->next = NIL;
        }
        dealokasi(P);
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NIL && Prec->next != NIL) {
        address P = Prec->next;
        Prec->next = P->next;
        if (P->next != NIL) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        dealokasi(P);
    }
}
