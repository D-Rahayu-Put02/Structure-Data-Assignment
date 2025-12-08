# <h1 align="center">Laporan Praktikum Modul 7 Stack </h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori
- Pengertian Stack
    Stack adalah struktur data yang bekerja dengan dengan prinsip LiFO (Last in First Out), artinya elemen yang terakhir masuk akan menjadi yang pertama keluar. Dalam stack hanya ada satu pointer penting yaitu TOP yang menunjuk ke elemen paling atas, implementasi stack di modul ini menggunakan pointer seperti linked list, dengan node yang berisi info dan pointer next. Operasi utama pada stack adalah push untuk menambahkan elemen kebagian atas dan pop untuk mengambil sekaligus menghapus elemen paling atas. stack dianggap kosong jika TOP berniali NULL. Stack hanya bisa diakses dari bagian atas sehingga elemen dibawah nya tidak dapat diambil tanpa mengeluarkan elemen elemen di atas nya terlebih dahulu. 

## Guided

### 1. [Stack.h]

```C++
#ifndef STACK
#define STACK 
#define Nil nullptr

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);
#endif
```
Program ini merupakan implementasi Doubly Linked List yang digunakan untuk mengelola data playlist lagu, di mana setiap node menyimpan informasi lagu dan terhubung dua arah. Program menyediakan fungsi untuk menambah, menghapus, memperbarui, menampilkan, serta mencari lagu berdasarkan nilai popularitas.

### 2. [DLLPlayList.cpp]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
Program ini merupakan implementasi lengkap Doubly Linked List untuk pengelolaan playlist lagu, yang mencakup proses alokasi dan dealokasi node, operasi penyisipan dan penghapusan di berbagai posisi, pembaruan data lagu, perhitungan skor popularitas, penelusuran data berdasarkan rentang skor, serta penampilan seluruh isi playlist secara terurut. Program ini mengatur setiap lagu sebagai node yang terhubung dua arah sehingga memudahkan manipulasi data playlist secara fleksibel.

### 3. [main.cpp]

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    return 0;
}
```
Program ini digunakan untuk mengatur data playlist lagu, seperti menambah, menghapus, menyisipkan, dan memperbarui lagu pada posisi tertentu.
Seluruh pengelolaan playlist dilakukan menggunakan struktur data Doubly Linked List, sehingga setiap lagu dapat diakses, dipindahkan, atau dimodifikasi melalui node yang saling terhubung dua arah.

## Unguided 
### 1. [doublelist.h]

```C++
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#define NIL NULL
#include <iostream>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int tahunbuat;
};

typedef kendaraan infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string nopol);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);

#endif
```
### 2. [doublelist.cpp]
```C++
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
```
### 3. [main.cpp]

```C++
#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;
    string nopolInput;

    // Input 4 kali sesuai contoh modul
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        // Cek duplikasi
        if (findElm(L, x.nopol) != NIL) {
            cout << "nomor polisi sudah terdaftar\n\n";
            // skip input warna/tahun kalau dupe
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> x.tahunbuat;

        cout << endl;

        P = alokasi(x);
        insertLast(L, P);
    }

    cout << "DATA LIST 1\n";
    printInfo(L);
    cout << endl;


    // ===== SOAL NOMOR 2 : Find D001 =====
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> nopolInput;

    address found = findElm(L, nopolInput);
    if (found != NIL) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.tahunbuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << endl;


    // ===== SOAL NOMOR 3 : Hapus =====
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolInput;

    address target = findElm(L, nopolInput);

    if (target != NIL) {
        if (target == L.first) {
            deleteFirst(L);
        } else if (target == L.last) {
            deleteLast(L);
        } else {
            deleteAfter(L, target->prev);
        }
        cout << "Data dengan nomor polisi " << nopolInput << " berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
```

#### Output:
<img width="1020" height="920" alt="image" src="https://github.com/user-attachments/assets/ead53e62-fdab-42d5-84a6-fa2a90b31401" />



Program ini dibuat untuk mengelola data kendaraan menggunakan Doubly Linked List.
Setiap node menyimpan nomor polisi, warna kendaraan, dan tahun pembuatan.
Program dapat melakukan:
- menambah data kendaraan ke belakang list (insertLast)
- menampilkan seluruh data (printInfo)
- mengecek apakah nopol sudah terdaftar (findElm)
- mencari data kendaraan tertentu
- menghapus data berdasarkan posisi (deleteFirst, deleteLast, deleteAfter)
- menolak input kendaraan dengan nopol yang sama (duplikasi)
Program ini mensimulasikan cara kerja struktur data Double Linked List untuk pengolahan data kendaraan secara dinamis.
#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/cb3d1f32-c50b-487f-b408-ae51c39b75b6" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/362d23f7-1a6d-48df-851b-5f8361dffdda" />

<img width="1917" height="1079" alt="image" src="https://github.com/user-attachments/assets/cae371a4-c2bb-432e-a55a-fcb7a56fb7ca" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. Pada modul ini dapat disimpulkan kalau Doubly Linked List sangat cocok digunakan untuk mengelola data secara dinamis karena setiap node memiliki pointer ke depan dan ke belakang.
Hal ini memudahkan proses penelusuran, pencarian, penambahan, maupun penghapusan data tanpa harus memindahkan seluruh elemen.
Struktur ini memberikan fleksibilitas lebih besar dibanding single linked list, terutama pada operasi delete dan insert di tengah list.



## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar


