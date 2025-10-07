# <h1 align="center">Laporan Praktikum Modu2 Pengenalan Bahasa C++ (2)</h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori

mengenal bahasa pemrograman C++, bahasa C++ merupakan bahasa yang unik yang di mana memerlukkan code khusus untuk memamnggil suatu character agar bisa di compile dan bisa di baca oleh komputer seperti #include <iostream> digunakan untuk mendeklarasikan library yang akan digunakan dalam program, bahasa C++ cukup banyak di gemari karena mudah di gunakan oleh banyak orang.

## Guided 

### 1. [array]

```C++
//array
#include <iostream>
using namespace std;

int main() {
    //---Array 1Dimensi ---
    int arr1D[5] = {10,20,30,40,50};
    cout << "Array 1 Dimensi: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
    }
    cout << endl;

    //---Array 2 Dimensi (baris x kolom)
    int arr2D[2] [3] = {
        {1,2,3},
        {4,5,6}
    };
    cout << "Array 2 Dimensi: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "] [" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;

    //---Array Multi Dimensi (3D)---
    int arr3D[2][2][3] = {
        { {1,2,3}, {4,5,6} },
        { {7,8,9}, {10,11,12} }
    };
    cout << "Array 3 Dimensi: " << endl;
    for (int i =0; i < 2; i++) {
        for (int j =0; j < 2; j++) {
            for (int k =0; k < 3; k++) {
                cout << "arr3D[" << i << "] [" << j <<"] ["
                << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }
    return 0;
}
```
program ini dibuat menggunakan bahasa pemrograman C++, program akan menghasilkan output sesuai masukkan yang ditulis oleh pengguna "Hello World".

### 2. [Produser]

```C++
//Prosedur
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke-: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "Jumlah Baris Kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
program input output jadi pengguna menginput variable bertipe int dengan const 3,14 cout di gunakan untuk wadah input dan cin sebagai wadah output program.

### 3. [Pointer]

```C++
//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
} 

int main() {
    int a =20, b =30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (Address of a): " << ptr << endl;
    cout << "Value pointes to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
    
}
```
program ini menampilkan bagaimana operasi dasar dan oprasi logika di jalankan penggunaan tanda +-*/% merupakan sistem operasi dasar.

### 4. [Refrence]

```C++
//refrence
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
} 

int main() {
    int a =20, b =30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (&ref): " << &ref << endl;

    // mengubah nilai a lewat refrence
    ref = 50;
    cout << "\nSetelah ref = 50:" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
    
}
```
program ini menggunakan if else untuk bisa beroperasi menentukkan output mana yang sesuai dengan inputan pengguna.

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

Kode di atas merupakan kode untuk membuat bilangan bertipe float bisa melakukkan operasi dasar penjumlahan, pengurangan, perkalian dan pembagian, program akan meminta 2 inputan bertipe float lalu program akan mengeksekusi operasi dasar yang sudah di siapkan dan program akan langsung menghasil kan output hasil dari oprasi dasar tersebut.

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/6a045365-2bcb-4b36-9e66-c57fcde87f3d" />


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
<img width="1377" height="303" alt="image" src="https://github.com/user-attachments/assets/e3aa73c0-670d-486c-9c64-37f1a2bd2983" />


Code di atas digunakan untuk mengubah angka atau tipe integer menjadi string, jadi si program akan meminta input berupa int lalu program akan mengecek di bagian if else apakah sesuai dengan aturan jika iya makan angka tersebut akan diubah lalu jika angka puluhan maka akan ada tambahan berupa string yang sudah di siapkan di string satuan (buat string satuan []) dan jika angkanya melebihi kapasitas maka output yang keluar "angka melebihi kapasitas".

#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/e27a31c1-a608-4d4d-92d8-f5b0aa638767" />


### 3. [Buat Segitiga Angka]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    if (!(cin >> n)) return 0;

    for (int i = n; i >= 0; i--) {
        // Spasi di depan
        for (int s = 0; s < n - i; s++) cout << "  ";

        //Angka menurun
        for (int a = i; a >= 1; a--) cout << a << " ";

        // Bintang di tengah
        cout << "* ";

        // Angka menaik
        for (int b = 1; b <= i; b++) cout << b << " ";

        cout << '\n';
    }

    return 0;
}

```
#### Output:
<img width="1359" height="272" alt="image" src="https://github.com/user-attachments/assets/73b7a654-53b6-47d9-ac51-aba9c1c2be62" />

Kode ini membuat urutan angka yang berbentuk segitiga sama sisi, pengguna akan menginput variable bertipe int lalu akan masuk ke perulangan yang akan menulis ulang angka yang di inputkan dari yang terbesar sampai terkecil dengan di batasi tanda bintang setiap for memilki fungsi masing-masing untuk bisa membuat bentuk segitiga.

#### Full code Screenshot:
<img width="1919" height="1078" alt="image" src="https://github.com/user-attachments/assets/8b954c7e-df0a-4c50-ba9c-28200fb562f2" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1]. pandangan ku di minggu pertama praktikum saya jadi bisa mengenal lebih dalam bahasa pemrograman C++ ini dari penggunaan dasar pemrograman, structure program, running code, compile code dan bentukan variblenya dengan belajar bahasa baru bisa menambah pengetahuan kalau bahasa program itu sangat beragam dan berbeda beda structure dan pembuatannya.   

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
