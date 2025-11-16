#include "ListIkan.h"

void createList(List &L) {
    L.first = Nil;
}

bool isEmpty(List L) {
    return (L.first == Nil);
}

address alokasi(string nama, float berat, int harga) {
    address P = new Node;
    P->info.nama = nama;
    P->info.berat = berat;
    P->info.harga = harga;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Nama ikan : " << P->info.nama << endl;
            cout << "Berat (kg): " << P->info.berat << endl;
            cout << "Harga/kg  : " << P->info.harga << endl;
            cout << "---------------------------" << endl;
            P = P->next;
        }
    }
}

address findIkan(List L, string nama) {
    address P = L.first;
    while (P != Nil && P->info.nama != nama) {
        P = P->next;
    }
    return P;
}

void updateIkan(List &L, string namaCari, float beratBaru, int hargaBaru) {
    address P = findIkan(L, namaCari);
    if (P != Nil) {
        P->info.berat = beratBaru;
        P->info.harga = hargaBaru;
        cout << "Data ikan " << namaCari << " berhasil diperbarui!" << endl;
    } else {
        cout << "Ikan " << namaCari << " tidak ditemukan dalam list." << endl;
    }
}

int totalHarga(List L) {
    address P = L.first;
    int total = 0;
    while (P != Nil) {
        total += (P->info.berat * P->info.harga);
        P = P->next;
    }
    return total;
}
