# <h1 align="center">Laporan Praktikum Modul 8 Queue </h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori
#### Queue

Queue merupakan struktur data yang dapat diumpamakan seperti sebuah antrean.
Misalkan antrean pada loket pembelian tiket Kereta Api. Orang yang akan mendapatkan pelayanan
yang pertama adalah orang pertamakali masuk dalam antrean tersebut dan yang terakhir masuk dia
akan mendapatkan layanan yang terakhir pula. Jadi prinsip dasar dalam Queue adalah FIFO (First in
Fisrt out), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian
struktur Queue dalam C dapat menggunakan tipe data array dan linked list.

#### 1. Operasi Dasar pada Queue
- Enqueue → menambahkan elemen ke dalam antrean (di bagian belakang / tail)
- Dequeue → menghapus elemen dari antrean (di bagian depan / head)
- Front / Peek → melihat elemen paling depan tanpa menghapusnya
- IsEmpty → mengecek apakah queue kosong
- IsFull (hanya pada implementasi berbasis array)

## Guided 

### 1. [Queu.h]

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang; 
    string Tujuan;
};

struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);

int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
```
Program ini digunakan untuk mengelola antrean paket ekspedisi menggunakan struktur queue. Di dalamnya terdapat fitur untuk menambah paket, menghapus paket, menampilkan antrean, serta menghitung total biaya pengiriman.

### 2. [Queu.cpp]

```C++
#include "queu.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    Paket P;
    cout << "Masukkan Kode Resi     : "; cin >> P.KodeResi;
    cout << "Masukkan Nama Pengirim : "; cin >> P.NamaPengirim;
    cout << "Masukkan Berat Barang  : "; cin >> P.BeratBarang;
    cout << "Masukkan Tujuan        : "; cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Menghapus paket dengan resi: " << Q.dataPaket[Q.Head].KodeResi << "\n";

    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.Tail--;

    if (Q.Tail < 0) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "\n--- Daftar Paket dalam Antrian ---\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Posisi " << i + 1 << ":\n";
        cout << "  Kode Resi     : " << Q.dataPaket[i].KodeResi << endl;
        cout << "  Pengirim      : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "  Berat Barang  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << "  Tujuan        : " << Q.dataPaket[i].Tujuan << endl;
        cout << "-----------------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}
```
Program ini berfungsi untuk mengelola antrean paket ekspedisi menggunakan struktur queue berbasis array. Didalamnya ada proses menambah paket (enqueue), menghapus paket (dequeue), menampilkan antrean, dan menghitung total biaya pengiriman berdasarkan berat barang. Program ini mensimulasikan sistem antrean pada layanan pengiriman paket.

### 3. [main.cpp]

```C++
#include <iostream>
#include "queu.h"

using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "\n--- Gojira Express ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "5. Exit\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            enQueue(Q);
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman: Rp. " 
                 << TotalBiayaPengiriman(Q) << endl;
            break;

        case 5:
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 5);

    return 0;
}
```
Program main() ini digunakan sebagai menu interaktif untuk menjalankan sistem antrean ekspedisi Gojira Express.

Melalui menu tersebut, pengguna bisa:
- Menambah data paket ke dalam antrean (enqueue)
- Menghapus paket terdepan (dequeue)
- Melihat seluruh paket dalam antrean
- Menghitung total biaya pengiriman
- Keluar dari program
program ini mensimulasikan sistem antrean layanan pengiriman paket menggunakan queue.

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


