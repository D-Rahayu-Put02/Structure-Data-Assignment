# <h1 align="center">Laporan Praktikum Modul 5 Singly Linked List (Bagian 2) </h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori

Searching
Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node
tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari
ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan
update akan lebih mudah.
Semua fungsi dasar di atas merupakan bagian dari ADT dari singgle linked list, dan aplikasi pada bahasa
pemrograman Cp semua ADT tersebut tersimpan dalam file *.c dan file *.h.

## Guided 

### 1. [listbuah.h]

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;
typedef struct node *address;

struct node {
    dataBuah isidata;
    address next;
};

struct linkedlist {
    address first;
};


bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &list);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedlist &List);
void updateLast(linkedlist &List);
void updateAfter(linkedlist &List, address prev);

// materi modul 5 (part 2, searching)
void FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, float hargaAwal, float hargaAkhir);

#endif
```
Program ini dibuat untuk mengelola data buah menggunakan struktur data linked list.
Dengan program ini, kita bisa:
Menyimpan data buah (nama, jumlah, harga) secara dinamis, menambah, menghapus, atau memperbarui data buah di mana saja dalam list, mencari data buah berdasarkan nama, alamat node, atau rentang harga, menampilkan semua data buah yang tersimpan dalam list.

### 2. [listbuah.cpp]

```C++
#include "buah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == NULL){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = NULL;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = NULL;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = NULL;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != NULL) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = NULL;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == NULL){
            List.first->next = NULL;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != NULL){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = NULL; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != NULL && nodePrev->next != NULL) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = NULL;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != NULL) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != NULL) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != NULL){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = NULL; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != NULL) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != NULL && nodePrev->next != NULL){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != NULL){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NULL) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != NULL) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
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

### 1. [Single List]

```C++
//singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define NIL NUL 

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Elmlist *address;

struct Elmlist{ 
    infotype info;
    address next;
};

struct List{
    address first;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);
void printInfo(List L);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```
Berisi deklarasi struktur data dan prototype fungsi, seperti ElmtList, List, serta fungsi CreateList, insert, delete, nbList, dan lainnya.
Fungsinya sebagai kerangka utama dari program agar bisa dipanggil di file lain.

```C++
//singlylist.cpp
#include "singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.first = NULL;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new Elmlist;
    P-> info = x;
    P-> next = NULL;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Insert di awal
void insertFirst(List &L, address P) {
    P-> next = L.first;
    L.first = P;
}

// Insert setelah node tertentu
void insertAfter(List &L, address P, address Prec) {
    if (Prec != NULL) {
        P-> next = Prec-> next;
        Prec-> next = P;
    }
}

// Insert di akhir
void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q-> next != NULL) {
            Q = Q-> next;
        }
        Q-> next = P;
    }
}

// Print isi list
void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List kosong." << endl;
    } else {
        address P = L.first;
        while (P != NULL) {
            cout << P-> info << " ";
            P = P-> next;
        }
        cout << endl;
    }
}

// Hapus node pertama
void deleteFirst(List &L) {
     if (L.first != NULL) {
        address P = L.first;
        L.first = P->next;
           dealokasi(P);
    }
}

// // Hapus node terakhir
void deleteLast(List &L) {
    if (L.first != NULL) {
        if (L.first->next == NULL) {
            dealokasi(L.first);
            L.first = NULL;
        } else {
            address P = L.first;
            address Prec = NULL;
            while (P->next != NULL) {
                Prec = P;
                P = P->next;
            }
            Prec->next = NULL;
            dealokasi(P);
        }
    }
}

// Hapus setelah node tertentu
void deleteAfter(List &L, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}


// func untuk menghapus list
void deleteList(List &L) {
     while (L.first != NULL) {
         deleteFirst(L);
     }
}
```
berisi semua implementasi mulai dari pembuatan list, alokasi node, operasi insert & delete, sampai menghitung jumlah node (nbList) dan menghapus semua node (deleteList).

```C++
//main.cpp
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
```
Program menambahkan beberapa data ke list, menampilkan isi list, lalu melakukan operasi penghapusan dan menampilkan hasil akhirnya.

#### Output:
<img width="992" height="245" alt="image" src="https://github.com/user-attachments/assets/f08a2feb-9c01-499e-af45-5b8c13d8defe" />


Program ini digunakan untuk mengelola data secara dinamis menggunakan struktur Single Linked List, di mana data dapat ditambahkan, dihapus, dan ditampilkan dengan memanfaatkan konsep pointer pada bahasa C++.

#### Full code Screenshot:
<img width="1915" height="1029" alt="image" src="https://github.com/user-attachments/assets/86a1b4a7-bdf9-4fa4-a8e4-8c10a3e0c5e5" />



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. Pada modul ini dipelajari cara membuat, menambah, menghapus, dan menampilkan node dalam linked list menggunakan pointer.
Kita juga belajar fungsi seperti insertFirst, insertLast, deleteFirst, deleteLast, dan nbList.
Intinya, modul ini melatih pemahaman tentang manajemen memori dan hubungan antar data secara dinamis.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar

