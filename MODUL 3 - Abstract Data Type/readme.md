# <h1 align="center">Laporan Praktikum Modul 3 Abstract Data Type (ADT)</h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori

ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam
sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT
merupakan definisi STATIK.
Definisi type dari sebuah ADT dapat mengandung sebuah definisi ADT lain. Misalnya :

- ADT waktu yang terdiri dari ADT JAM dan ADT DATE

- Garis terdiri dari duah buah ADT POINT

SEGI4 yang terdiri dari pasangan dua buah POINT (Top,Left) dan (Bottom,Right)
TYPE diterjemahkan menjadi type terdefinisi dalam bahasa yang bersangkutan. Jika dalam bahasa C
menggunakan struct PRIMITIF, dalam konteks prosedural, diterjemahkan menjadi fungsi atau
prosedur. 

## Guided 

### 1. [mahasiswa.h]

```C++
//array
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputmhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif

```
program ini menunjukkan penggunaan array 1 dimensi, 2 dimensi dan 3 dimensi pada program C++, array 1 dimensi digunakan untuk menyimpan data dalam baris, 2 dimensi untuk menyimpan data array dalam bentuk baris dan kolom sedangkan yang 3 dimensi digunakan untuk data yang memiliki lebih dari dua lapisan baris dan kolom.

### 2. [mahasiswa.cpp]

```C++
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputmhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai1 = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;

}

float rata2(mahasiswa m) {
    return (m.nilai1 + m.nilai2) /2.0;
}
```
program ini menggunakan pointer untuk menukar dua nilai variable, pointer menyimpan alamat dari variable a sehingga nilai a bisa di akses oleh *ptr. fungsi tukar() menerima alamt a dan b lalu menukar nilainya.

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
Program ini menggunakan reference untuk menukar nilai dua variabel. Reference (ref) berfungsi sebagai alias dari variabel a, sehingga perubahan pada ref juga mengubah a. Fungsi tukar() menukar nilai a dan b tanpa menggunakan pointer.
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

Program ini dibuat untuk melakukan operasi dasar penjumlahan, pengurangan dan perkalian terhadap 2 buah matrix dengan ukuran 3x3, program akan meminta input untuk kedua matrix yang akan di lakukan operasi dasar, lalu program akan melanjutkan ke proses operasi dasar yang sudah di buat lalu hasil akan di simpan di matrix C, output nya bentuk matrix 3x3 dengan hasil dari masing masing operasi dasar.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/8f13324c-89d2-4754-9400-a4614d6a3f9d" />


### 2. [Menukar nilai variable]

```C++
#include <iostream>
using namespace std;

//Pakai Pointer
void Pointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}
//Pakai Refrence
void Refrence(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a,b,c;

    cout << "TUKAR NILAI" << endl;
    cout << "Masukkan Nilai a = ";
    cin >> a;
    cout << "Masukkan Nilai b = ";
    cin >> b;
    cout << "Masukkan Nilai c = ";
    cin >> c;

    cout << "\nNILAI AWAL" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Tukar Pakai Pointer
    Pointer(&a, &b, &c);
    cout << "\nPakai Pointer" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // Tukar Pakai Refrence
    Refrence(a, b, c);
    cout << "\nPakai Pointer" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;

}
```
#### Output:
<img width="1536" height="423" alt="image" src="https://github.com/user-attachments/assets/c42937a8-5977-4be4-b3d0-815359c8d4bc" />


program ini di buat untuk menukar 3 nilai variable menggunakan 2 cara yaitu pointer dan refrence, sebelum melakukan penukaran program akan minta input angka apa saja yang akan di tukar, lalu program akan menjalankan void pertama pertukaran nilai menggunakan pointer kemudian dilanjutkan dengan cara kedua untuk melakukakan petukaran menggunakan fungsi refrence, output yang di hasilkan adalah hasil dari proses pertukaran 3 variable menggunakan dua cara.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/c8d83ee0-b919-4ff5-b869-b2ec13794b59" />


### 3. [array 1 dimensi]

```C++
#include <iostream>
using namespace std;

//fungsi mencari nilai min
int Minimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

//fungsi mencari niai max
int Maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

//fungsi cari nilai rata rata
void Ratarata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    float rata = total / n;
    cout << "Nilai rata-rata = " << rata << endl;
}


int main() {
    int arrA[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int pilih;

    do {
        cout << "\n---Menu Program Array---\n" << endl;
        cout << "1.Tampilkan Array" << endl;
        cout << "2.Cari Nilai Maximum" << endl;
        cout << "3.Cari Nilai Minimum" << endl;
        cout << "4.Hitung Rata Rata" << endl;
        cout << "5.Keluar\n" << endl;
        cout << "Pilih menu (1-5):";
        cin >> pilih;

        switch (pilih) {
             case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << Maximum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << Minimum(arrA, n) << endl;
                break;
            case 4:
                Ratarata(arrA, n);
                break;
            case 5:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Tidak ada yang sesuai\n";
        }
    } while (pilih !=5);
    return 0;
}

```
#### Output:
<img width="1330" height="849" alt="image" src="https://github.com/user-attachments/assets/40a13c52-f9e3-43b3-94a2-d041a962e842" />

Program ini di buat untuk mengolah data array 1 dimensi untuk mencari nilai maximal, minimum dan nilai rata rata, terdapat menu switch case supaya pengguna bisa memilih opsi menu mencari nilai min, max dan rata rata. 

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/344b529b-6319-409b-8a98-7fc8ad669e04" />



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. pandangan ku pada minggu kedua ini, dengan memahami bagaimana cara membuat fungsi terpisah di C++ dapat memudahkan pembuatan program dan program jadi terlihat tersusun rapi, dengan mempelajari pointer dan refrence kita jadi bisa memahami bagaimana cara memori itu bekerja. pengetahuan ini juga menjadi dasar penting untuk memahami konsep struktur data dan pemrograman yang lebih kompleks di modul berikutnya.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
