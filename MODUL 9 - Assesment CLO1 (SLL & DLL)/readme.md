# <h1 align="center">Laporan Praktikum Modul 9 Assesment CLO1 (SLL & DLL) </h1>
<p align="center">Dwi Rahayu Putra</p>

## SOAL 1
Buatlah ADT Single Linked List (SLL) untuk menyimpan data produk toko dalam file

```C++
//Ases.h
#ifndef ASES_H
#define ASES_H

#include <iostream>
#include <string>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef struct Node* address;

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Product P);
void deallocate(address P);

void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);

void updateAtPosition(List &L, int posisi);

void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

void MaxHargaAkhir(List L);

#endif
```
```C++
//ases.cpp
#include "ases.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
}

address allocate(Product P) {
    address newNode = new Node;
    newNode->info = P;
    newNode->next = nullptr;
    return newNode;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, Product P) {
    address newNode = allocate(P);
    newNode->next = L.head;
    L.head = newNode;
}

void insertLast(List &L, Product P) {
    address newNode = allocate(P);
    if (isEmpty(L)) {
        L.head = newNode;
    } else {
        address temp = L.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != nullptr) {
        address newNode = allocate(P);
        newNode->next = Q->next;
        Q->next = newNode;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        P = temp->info;
        L.head = temp->next;
        deallocate(temp);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        if (L.head->next == nullptr) {
            P = L.head->info;
            deallocate(L.head);
            L.head = nullptr;
        } else {
            address temp = L.head;
            address prev = nullptr;

            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            P = temp->info;
            prev->next = nullptr;
            deallocate(temp);
        }
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != nullptr && Q->next != nullptr) {
        address temp = Q->next;
        P = temp->info;
        Q->next = temp->next;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi) {
    address temp = L.head;
    int index = 1;

    while (temp != nullptr && index < posisi) {
        temp = temp->next;
        index++;
    }

    if (temp != nullptr) {
        cout << "Masukkan Nama baru: ";
        cin >> temp->info.Nama;
        cout << "Masukkan SKU baru: ";
        cin >> temp->info.SKU;
        cout << "Masukkan Jumlah baru: ";
        cin >> temp->info.Jumlah;
        cout << "Masukkan HargaSatuan baru: ";
        cin >> temp->info.HargaSatuan;
        cout << "Masukkan DiskonPersen baru: ";
        cin >> temp->info.DiskonPersen;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address temp = L.head;
    int idx = 1;
    while (temp != nullptr) {
        float hargaAkhir = temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

        cout << idx << ". "
             << temp->info.Nama << " | "
             << temp->info.SKU << " | "
             << temp->info.Jumlah << " | "
             << temp->info.HargaSatuan << " | "
             << temp->info.DiskonPersen << "% | "
             << "Harga Akhir: " << hargaAkhir << endl;

        temp = temp->next;
        idx++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    address temp = L.head;
    int idx = 1;

    cout << "Hasil pencarian harga akhir dalam range [" << minPrice << ", " << maxPrice << "]\n";

    while (temp != nullptr) {
        float hargaAkhir = temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            cout << idx << ". " << temp->info.Nama
                 << " (Harga Akhir: " << hargaAkhir << ")\n";
        }
        temp = temp->next;
        idx++;
    }
}

void MaxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    float maxHarga = -1;
    address temp = L.head;

    // Cari harga akhir terbesar
    while (temp != nullptr) {
        float hargaAkhir = temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);
        if (hargaAkhir > maxHarga) {
            maxHarga = hargaAkhir;
        }
        temp = temp->next;
    }

    cout << "\nProduk dengan HargaAkhir terbesar (" << maxHarga << "):\n";

    temp = L.head;
    int idx = 1;
    while (temp != nullptr) {
        float hargaAkhir = temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);
        if (hargaAkhir == maxHarga) {
            cout << idx << ". " << temp->info.Nama 
                 << " | SKU: " << temp->info.SKU 
                 << " | Harga Akhir: " << hargaAkhir << endl;
        }
        temp = temp->next;
        idx++;
    }
}
```
```C++
//main
#include "ases.h"

int main() {
    List L;
    createList(L);

    insertLast(L, {"Pulpen", "A001", 20, 2500, 0});
    insertLast(L, {"Buku Tulis", "A002", 15, 5000, 10});
    insertLast(L, {"Penghapus", "A003", 30, 1500, 0});

    cout << "\n=== List Awal ===\n";
    viewList(L);

    Product removed;
    deleteFirst(L, removed);

    cout << "\n=== Setelah deleteFirst ===\n";
    viewList(L);

    cout << "\n=== Update posisi ke-2 ===\n";
    updateAtPosition(L, 2);

    cout << "\n=== Setelah Update ===\n";
    viewList(L);

    cout << "\n=== Searching HargaAkhir 2000 - 7000 ===\n";
    searchByFinalPriceRange(L, 2000, 7000);

    cout << "\n=== MaxHargaAkhir ===\n";
    MaxHargaAkhir(L);

    return 0;
}
```

##OUTPUT

<img width="624" height="572" alt="image" src="https://github.com/user-attachments/assets/a556fa75-e607-427b-a51c-bda8d118183e" />

##SOAL 2
```C++
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;    
};

typedef struct Node* address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address Q);

void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

float getPopularityScore(Song S);

#endif
```
```C++
#include "DLLPlaylist.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void deallocate(address P) {
    delete P;
}

float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q != nullptr) {
        address P = allocate(S);
        P->next = Q->next;
        P->prev = Q;

        if (Q->next != nullptr)
            Q->next->prev = P;
        else
            L.tail = P;

        Q->next = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q != nullptr) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;

            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.head;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.head = P->next;
            L.head->prev = nullptr;
        }
        deallocate(P);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.tail;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.tail = P->prev;
            L.tail->next = nullptr;
        }
        deallocate(P);
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->next != nullptr) {
        address P = Q->next;
        S = P->info;

        Q->next = P->next;
        if (P->next != nullptr)
            P->next->prev = Q;
        else
            L.tail = Q;

        deallocate(P);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;
        S = P->info;

        if (P == L.head) {
            deleteFirst(L, S);
        } else {
            P->prev->next = Q;
            Q->prev = P->prev;
            deallocate(P);
        }
    }
}

void updateAtPosition(List &L, int posisi) {
    int idx = 1;
    address P = L.head;

    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != nullptr) {
        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void updateBefore(List &L, address Q) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;

        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int idx = 1;

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        cout << idx << ". "
             << P->info.Title << " | " << P->info.Artist
             << " | " << P->info.DurationSec << "s | PC: "
             << P->info.PlayCount << " | Rating: "
             << P->info.Rating << " | PopularityScore: "
             << pop << endl;

        P = P->next;
        idx++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address P = L.head;
    int idx = 1;

    cout << "\nHasil searching PopularityScore in [" 
         << minScore << ", " << maxScore << "]\n";

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        if (pop >= minScore && pop <= maxScore) {
            cout << idx << ". " << P->info.Title 
                 << " | PopularityScore: " << pop << endl;
        }

        P = P->next;
        idx++;
    }
}
```
```C++
#include "DLLPlaylist.h"

address getNodeAt(List L, int posisi) {
    int idx = 1;
    address P = L.head;
    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }
    return P;
}

int main() {
    List L;
    createList(L);

    insertLast(L, {"Senja di Kota", "Nona Band", 210, 150, 4.2});
    insertLast(L, {"Langkahmu", "Delta", 185, 320, 4.8});
    insertLast(L, {"Hujan Minggu", "Arka", 240, 90, 3.95});

    cout << "\n=== List Awal ===\n";
    viewList(L);

    Song removed;
    deleteLast(L, removed);

    cout << "\n Setelah deleteLast \n";
    viewList(L);

    cout << "\n Update posisi ke-2 \n";
    updateAtPosition(L, 2);

    cout << "\n Setelah Update \n";
    viewList(L);

    address pos2 = getNodeAt(L, 2);

    insertBefore(L, pos2, {"Senandung", "Mira", 175, 120, 4.0});
    cout << "\n Setelah insertBefore posisi 2 \n";
    viewList(L);

    cout << "\n UpdateBefore posisi 2 \n";
    pos2 = getNodeAt(L, 2);
    updateBefore(L, pos2);

    cout << "\n Setelah updateBefore \n";
    viewList(L);

    cout << "\n deleteBefore posisi 3 \n";
    Song removed2;
    address pos3 = getNodeAt(L, 3);
    deleteBefore(L, pos3, removed2);

    cout << "\n Setelah deleteBefore \n";
    viewList(L);

    cout << "\n Searching PopularityScore 150–300 \n";
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}
```
##OUTPUT

<img width="1102" height="773" alt="image" src="https://github.com/user-attachments/assets/8330642e-319b-4b49-ae78-e189786726c9" />
