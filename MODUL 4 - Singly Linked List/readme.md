# <h1 align="center">Laporan Praktikum Modul 4 Singly Linked List </h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori

Singly Linked List (biasa di sebut list) adalah salah satu bentuk struktur data (representasi peyimpanan) yang terdiri dari serangkaian elemen data yang saling terhubung (berkaitan) dan bersifat fleksibel, karena ukurannya bisa bertambah atau berkurang sesuai kebutuhan. setiap elemen dalam linked list disebut node, yang berisi data atau pointer yang menunjuk ke node berikutnya.

Linked list digunakkan untuk menyimpan data baik yang bersifat tunggal (satu variable) atau majemuk (beberapa variable).

## Guided 

### 1. [list.h]

```C++
#ifndef LIST_H
#define LIST_H
#define NIL NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa datamahasiswa;

typedef struct node *address;

struct node{
    datamahasiswa isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist list);
void createList(linkedlist &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodebaru);
void insertAfter(linkedlist &list, address nodebaru, address prev);
void insertLast(linkedlist &list, address nodebaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodeprev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

#endif

```
program digunakan untuk membuat struct mahasiswa yang terdiri dari char nim dan nilai1, nilai2.
### 2. [list.cpp]

```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == NIL){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = NIL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = NIL;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = NIL;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != NIL) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NIL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NIL) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
program ini digunakan untuk menyimpan void input yang berfungsi untuk menampilkan input nama, nilai1, dan nilai2, disini juga ada proses untuk menghitung rata rata dari nilai1 dan nilai2 kemudian di bagi 2.0.

### 3. [main.cpp]

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputmhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}

```
program ini merupakan file utama untuk menjalankan dan menyatukan semua program yang sudah di buat di atas.
.

## Unguided 

### 1. [Nilai Mahasiswa]

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitung(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitung(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n--- Data Mahasiswa ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
        cout << "---------------------------\n";

    }

    return 0;
}

```
#### Output:
<img width="1374" height="950" alt="image" src="https://github.com/user-attachments/assets/0e96e068-6d16-4b95-a6c1-1700040b80b3" />

Program ini menyimpan data mahasiswa maximal sebanyak sepuluh orang kedalam array yang berisi nama, nim, nilai uts, uas, tugas dan nilai akhir, nilai akhir akan di hitung menggunakan rumus pada code (hitung) yang sudah di buat, jadi intinya program ini melatih penggunaan array of struct, input/output dan fungsi perhitungan sederhana untuk menghitung nilai akhir mahasiswa.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/8f13324c-89d2-4754-9400-a4614d6a3f9d" />


### 2. [Nama Matkul]

```C++
//pelajaran.h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};

Pelajaran create_pelajaran(string nama, string kode);
void tampil_pelajaran(Pelajaran pel);

#endif
```
berisi deklarasi struct dan fungsi, struct ini dipakai untuk menyimpan data nama pelajaran.
```C++
//pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

Pelajaran create_pelajaran(string nama, string kode) {
    Pelajaran p;
    p.namaMapel = nama;
    p.kodeMapel = kode;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Nilai          : " << pel.kodeMapel << endl;
}D
```
berisi implementasi fungsi fungsi yang ada di header.
```C++
//main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    Pelajaran pel = create_pelajaran(namaPel, kodePel);

    tampil_pelajaran(pel);

    return 0;
}
```
file utama untuk menjalankan program.

#### Output:
<img width="1147" height="169" alt="image" src="https://github.com/user-attachments/assets/f5f7ae41-0410-458a-beef-85ec5c75b3de" />


Program ini menggunakan ADT (Abstract Data Type) untuk menyimpan dan menampilkan data pelajaran. Struct Pelajaran berisi nama dan kode mapel, lalu ada fungsi create_pelajaran untuk membuat data baru dan tampil_pelajaran untuk menampilkannya. Program ini menunjukkan cara memisahkan data dan fungsinya agar kode lebih rapi dan terstruktur.

#### Full code Screenshot:
<img width="1914" height="1004" alt="image" src="https://github.com/user-attachments/assets/e9562d1d-f244-4357-b7d6-c399ca5c29fd" />
<img width="1906" height="1013" alt="image" src="https://github.com/user-attachments/assets/55c95bd3-54ad-4a7b-84ac-8708e89289c8" />
<img width="1918" height="1055" alt="image" src="https://github.com/user-attachments/assets/3b56ec3d-7a7d-4147-90fd-739e153cebe9" />


### 3. [Tukar array 2D]

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarPosisi(A, B, 0, 0);

    cout << "\nSetelah tukar posisi (baris 1 kolom 1):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    int x = 100, y = 200;
    int* px = &x;
    int* py = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(px, py);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
```
#### Output:
<img width="1535" height="556" alt="image" src="https://github.com/user-attachments/assets/110493da-96bd-4402-9334-aef498fcfdbc" />

Program ini menampilkan cara menukar nilai antar elemen array 2 dimensi dan antar variabel menggunakan pointer. Fungsi tukarPosisi menukar elemen dua array di posisi tertentu, sedangkan tukarPointer menukar nilai dua variabel lewat pointer. Program ini menunjukkan penggunaan array, fungsi, dan pointer dalam C++. 

#### Full code Screenshot:
<img width="1919" height="1011" alt="image" src="https://github.com/user-attachments/assets/70c45fad-5ed0-48c6-8f3a-1e45d0ba4d3f" />



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. pandangan ku pada minggu ketiga, setelah memasuki modul 3 konsep ADT (Abtract Data Type) membantu agar membuat program terlihat rapi dan mudah untuk di pahami, dengan memisahkan data dan fungsi di file yang berbeda membuat program menjadi terstruktur, konsep ini mempermudah mengelola dan mengubah data tanpa terganggu bagian lain.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar

