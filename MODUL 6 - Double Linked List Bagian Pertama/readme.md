# <h1 align="center">Laporan Praktikum Modul 6 Double Linked List (Bagian 1) </h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori
Double Linked List

Doubly Linked list adalah linked list yang masing – masing elemen nya memiliki 2 successor, yaitu
successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen
sesudahnya (next).

Doubly linked list juga menggunakan dua buah successor utama yang terdapat pada list, yaitu first
(successor yang menunjuk elemen pertama) dan last (susesor yang menunjuk elemen terakhir list).
Komponen-komponen dalam Doubly linked list:
1. First : pointer pada list yang menunjuk pada elemen pertama list.
2. Last : pointer pada list yang menunjuk pada elemen terakhir list.
3. Next : pointer pada elemen sebagai successor yang menunjuk pada elemen didepannya.
4. Prev : pointer pada elemen sebagai successor yang menunjuk pada elemen dibelakangnya.


## Guided 

### 1. [DLLPlayList.h]

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
Program ini dibuat untuk mengelola data buah menggunakan struktur data linked list.
Dengan program ini, kita bisa:
Menyimpan data buah (nama, jumlah, harga) secara dinamis, menambah, menghapus, atau memperbarui data buah di mana saja dalam list, mencari data buah berdasarkan nama, alamat node, atau rentang harga, menampilkan semua data buah yang tersimpan dalam list.

### 2. [DLLPlayList.cpp]

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
Program di atas adalah implementasi struktur data singly linked list dalam bahasa C++ untuk menyimpan data buah yang berisi:
- nama buah (string)
- jumlah buah (int)
- harga buah (float)

### 3. [main.cpp]

```C++
#include "buah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Apel", 100, 20000);
    nodeB = alokasi("Cemangka", 75, 21000);
    nodeC = alokasi("Apple", 87, 20000);
    nodeD = alokasi("Tomato", 43, 21000);
    nodeE = alokasi("Duren", 70, 50000);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node: " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kalpa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 50, 1000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeA, nodeB);

     cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

     deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah Node: " << nbList(List) << endl;
    cout << endl;
    return 0;
}

```
Program main() di atas adalah program utama untuk menguji semua fungsi linked list yang sudah kamu buat di file buah.cpp.

## Unguided 
untuk latihan soal saya menggunakan tema tempat pemancingan untuk mennetukkan harga ikan yang akan di jual
### 1. [Listikan.h]

```C++
//listikan.h
#ifndef LISTIKAN_H
#define LISTIKAN_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct ikan {
    string nama;
    float berat;
    int harga; 
};

typedef ikan infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
bool isEmpty(List L);
address alokasi(string nama, float berat, int harga);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findIkan(List L, string nama);
void updateIkan(List &L, string namaCari, float beratBaru, int hargaBaru);
int totalHarga(List L);

#endif
```

```C++
//listikan.cpp
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
```

```C++
//main.cpp
#include "ListIkan.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi("Lele", 2.5, 20000));
    insertLast(L, alokasi("Gurame", 1.2, 35000));
    insertLast(L, alokasi("Patin", 3.0, 25000));
    insertLast(L, alokasi("Nila", 2.0, 30000));

    cout << "=== Data Ikan Hasil Pancingan ===" << endl;
    printInfo(L);

    cout << "\nCari ikan 'Patin':" << endl;
    address cari = findIkan(L, "Patin");
    if (cari != Nil)
        cout << "Ikan ditemukan! Berat: " << cari->info.berat << " kg, Harga/kg: " << cari->info.harga << endl;
    else
        cout << "Ikan tidak ditemukan." << endl;

    cout << "\nUpdate ikan 'Lele' jadi berat 3 kg dan harga 22000/kg" << endl;
    updateIkan(L, "Lele", 3.0, 22000);

    cout << "\n=== Data Setelah Update ===" << endl;
    printInfo(L);

    int total = totalHarga(L);
    cout << "\nTotal harga semua ikan: Rp " << total << endl;

    return 0;
}
```

#### Output:
<img width="1051" height="816" alt="image" src="https://github.com/user-attachments/assets/c9f2967d-be30-4eec-a27b-3b7a801f3814" />

program ini digunakan untuk mengelola data hasil pemancingan menggunakan struktur data singly linked list, didalam program, setiap node mewakili seekor ikan yang terdiri dari nama ikan, berat dan harganya, dengan linked list, program bisa menambahkan di list tertentu, menghapus data ikan, mengupdate data ikan, mencari data ikan berdasarkan nama, alamat dan rata rata harga, menampilkan semua data ikan dan bisa menghitung jumlah data.

#### Full code Screenshot:
<img width="1916" height="993" alt="image" src="https://github.com/user-attachments/assets/2549e94c-b321-4029-b69a-3b742d129a6c" />




## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. Pada modul ini dipelajari cara membuat, menambah, menghapus, menampilkan dan mencari node dalam linked list menggunakan pointer berdasarkan nama, alamat dan harga.
Secara keseluruhan, program pemancingan ini membantu mempelajari manajemen memori dinamis, pointer, dan struktur data linked list, dalam tema pemancingan, sama seperti materi pada modul sebelumnya hanya saja pada program kali ini ada tambahan program baru yaitu serching untuk mencari data ikan sesuai nama, alamat node dan rata rata harga.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar


