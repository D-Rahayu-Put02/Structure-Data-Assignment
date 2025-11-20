# <h1 align="center">Laporan Praktikum Modul 15 Assesment CLO2 (STACK & QUEU) </h1>
<p align="center">Dwi Rahayu Putra</p>

## SOAL 1
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file

```C++
#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);
void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S);
void Pop(StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi);
void View(StackMahasiswa &S);
float HitungNilaiAkhir(Mahasiswa M);
void SearchNilaiAkhir(StackMahasiswa &S, float minAkhir, float maxAkhir);

void MaxNilaiAkhir(StackMahasiswa &S);

#endif
```
```C++
#include "stackmahasiswa.h"

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S) {
    if (isFull(S)) {
        cout << "Stack penuh!\n";
        return;
    }

    S.Top++;
    cout << "Input Nama     : ";
    cin >> S.dataMahasiswa[S.Top].Nama;
    cout << "Input NIM      : ";
    cin >> S.dataMahasiswa[S.Top].NIM;
    cout << "Input Tugas    : ";
    cin >> S.dataMahasiswa[S.Top].NilaiTugas;
    cout << "Input UTS      : ";
    cin >> S.dataMahasiswa[S.Top].NilaiUTS;
    cout << "Input UAS      : ";
    cin >> S.dataMahasiswa[S.Top].NilaiUAS;
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }
    S.Top--;
}

void Update(StackMahasiswa &S, int posisi) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }
    if (posisi < 1 || posisi > S.Top + 1) {
        cout << "Posisi tidak valid!\n";
        return;
    }

    int index = posisi - 1;

    cout << "\n=== Update data posisi " << posisi << " ===\n";
    cout << "Nama baru : ";
    cin >> S.dataMahasiswa[index].Nama;
    cout << "NIM baru : ";
    cin >> S.dataMahasiswa[index].NIM;
    cout << "Nilai Tugas baru : ";
    cin >> S.dataMahasiswa[index].NilaiTugas;
    cout << "Nilai UTS baru   : ";
    cin >> S.dataMahasiswa[index].NilaiUTS;
    cout << "Nilai UAS baru   : ";
    cin >> S.dataMahasiswa[index].NilaiUAS;
}

float HitungNilaiAkhir(Mahasiswa M) {
    return 0.2 * M.NilaiTugas + 0.4 * M.NilaiUTS + 0.4 * M.NilaiUAS;
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "\n Isi Stack Mahasiswa \n";
    for (int i = S.Top; i >= 0; i--) {
        cout << "Posisi " << i + 1 << endl;
        cout << "Nama   : " << S.dataMahasiswa[i].Nama << endl;
        cout << "NIM    : " << S.dataMahasiswa[i].NIM << endl;
        cout << "Tugas  : " << S.dataMahasiswa[i].NilaiTugas << endl;
        cout << "UTS    : " << S.dataMahasiswa[i].NilaiUTS << endl;
        cout << "UAS    : " << S.dataMahasiswa[i].NilaiUAS << endl;
        cout << "Nilai Akhir : " << HitungNilaiAkhir(S.dataMahasiswa[i]) << endl;
        cout << "-----------------------\n";
    }
}

void SearchNilaiAkhir(StackMahasiswa &S, float minAkhir, float maxAkhir) {
    cout << "\n Hasil Searching NilaiAkhir " 
         << minAkhir << " - " << maxAkhir << " \n";

    for (int i = S.Top; i >= 0; i--) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA >= minAkhir && NA <= maxAkhir) {
            cout << "Ditemukan pada posisi " << i + 1 << endl;
            cout << S.dataMahasiswa[i].Nama << " | Nilai Akhir: " << NA << endl;
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    float maxNA = HitungNilaiAkhir(S.dataMahasiswa[0]);

    for (int i = 1; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA > maxNA)
            maxNA = NA;
    }

    cout << "\n Data NilaiAkhir Terbesar \n";
    for (int i = 0; i <= S.Top; i++) {
        float NA = HitungNilaiAkhir(S.dataMahasiswa[i]);
        if (NA == maxNA) {
            cout << "Posisi " << i + 1 << endl;
            cout << S.dataMahasiswa[i].Nama 
                 << " | Nilai Akhir: " << NA << endl;
        }
    }
}
```
```C++
#include "stackmahasiswa.h"

int main() {
    StackMahasiswa S;
    createStack(S);

    S.Top++; S.dataMahasiswa[S.Top] = {"Venti", "11111", 75.7, 82.1, 65.5};
    S.Top++; S.dataMahasiswa[S.Top] = {"Xiao", "22222", 87.4, 88.9, 81.9};
    S.Top++; S.dataMahasiswa[S.Top] = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    S.Top++; S.dataMahasiswa[S.Top] = {"Wanderer7", "44444", 95.5, 85.5, 90.5};
    S.Top++; S.dataMahasiswa[S.Top] = {"Lynette", "55555", 77.7, 65.4, 79.9};
    S.Top++; S.dataMahasiswa[S.Top] = {"Chasca", "66666", 99.9, 93.6, 87.3};

    cout << "\n Stack Setelah Input \n";
    View(S);

    Pop(S);

    cout << "\n Stack Setelah Pop 1x \n";
    View(S);

    S.dataMahasiswa[2] = {"Heizou", "77777", 99.9, 88.8, 77.7};

    cout << "\n Setelah Update Posisi ke-3 \n";
    View(S);

    cout << "\n Searching NilaiAkhir 85.5 - 95.5 \n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    MaxNilaiAkhir(S);

    return 0;
}
```

##OUTPUT

<img width="920" height="889" alt="image" src="https://github.com/user-attachments/assets/aa473a99-96f6-4cbc-9dc3-514508d6fbcb" />

##SOAL 2
Buatlah ADT queue menggunakan ARRAY sebagai berikut

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
##OUTPUT

<img width="774" height="870" alt="image" src="https://github.com/user-attachments/assets/114f0917-f8fe-411f-bc57-b0f0a6680e18" />

