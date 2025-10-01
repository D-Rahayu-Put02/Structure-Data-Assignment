# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Pemrograman

.

## Guided 

### 1. [Cetak text]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
```
program ini dibuat menggunakan bahasa pemrograman C++, program akan menghasilkan output sesuai masukkan yang ditulis oleh pengguna.

## Unguided 

### 1. [Operasi Dasar]

```C++
#include <iostream>
using namespace std;

int main(){
    float a;
    float b;

    //Inputan
     cout << "masukkan angka 1: " << endl;
     cin >> a;
     cout << "masukkan angka 2: " << endl;
     cin >> b;

    //Operasi Dasar
    cout << "Hasil Penjumlahan = " << (a+b) << endl;
    cout << "Hasil Pengurangan = " << (a-b) << endl;
    cout << "Hasil Perkalian = " << (a*b) << endl;
    cout << "Hasil Pembagian = " << (a/b) << endl;

    return 0;
}
```
#### Output:
<img width="1379" height="284" alt="image" src="https://github.com/user-attachments/assets/51a8cf20-135c-4bb4-8f1d-c7d091ea2a86" />

code di atas merupakan code untuk membuat bilangan bertipe float bisa melakukkan operasi dasar penjumlahan, pengurangan, perkalian dan pembagian, program akan meminta 2 inputan bertipe float agar bisa menjalankan operasi dasar.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

### 2. [Mengubah Angka Menjadi String]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "";
    cin >> n;

    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima",
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    string hasil;

    if (n < 12) {
        hasil = satuan[n];
    } else if (n < 20) {
        hasil = satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        hasil = satuan[puluh] + " puluh";
        if (sisa != 0) hasil += " " + satuan[sisa];
    } else if (n == 100) {
        hasil = "seratus";
    } else {
        hasil = "angka melebihi kapasitas ";
    }

    cout << n << " : " << hasil << endl;

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
Keluaran:
240302_00h00m06s_tangkapan layar

Kode di atas digunakan untuk mencetak teks "ini adalah kode file yang dipandu praktikan" ke layar menggunakan fungsi cout untuk mengeksekusinya.

Tangkapan Layar Kode Lengkap:
240309_10h21m35s_tangkapan layar

Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

Referensi
[1] I. Holm, Narator, dan J. Fullerton-Smith, Produser, Cara Membangun Manusia [DVD]. London: BBC; 2002.
