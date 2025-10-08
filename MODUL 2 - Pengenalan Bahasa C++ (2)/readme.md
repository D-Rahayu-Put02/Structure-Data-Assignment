# <h1 align="center">Laporan Praktikum Modul 2 Pengenalan Bahasa C++ (2)</h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori

mengenal bahasa pemrograman C++, bahasa C++ merupakan bahasa yang unik yang di mana memerlukkan code khusus untuk memamnggil suatu character agar bisa di compile dan bisa di baca oleh komputer seperti #include <iostream> digunakan untuk mendeklarasikan library yang akan digunakan dalam program, bahasa C++ cukup banyak di gemari karena mudah di gunakan oleh banyak orang sekaligus mendukung pemrograman prosedural.

Dalam modul ini toeri yang dipelajari adalah mengenai array satu dimensi, dua dimensi, tiga dimensi, function (void), prosedur, serta pointer dsn refrence sebagai cara untuk mengelola data di dalam memori, konsep ini penting untuk memahami carakerja memori, manipulasi data dan komunikasi antar fungsi dalam bahasa pemrograman C++. 

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
program ini menunjukkan penggunaan array 1 dimensi, 2 dimensi dan 3 dimensi pada program C++, array 1 dimensi digunakan untuk menyimpan data dalam baris, 2 dimensi untuk menyimpan data array dalam bentuk baris dan kolom sedangkan yang 3 dimensi digunakan untuk data yang memiliki lebih dari dua lapisan baris dan kolom.

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
program ini menggunakan prosedur tulis() untuk menampilkan sejumlah baris text yang dimasukkan pengguna. nilai input di dismpan pada variable jum, lalu dikirim ke prosedur untuk menampilkan perulangan for.

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
program ini menggunakan pointer untuk menukar dua nilai variable, pointer menyimpan alamat dari variable a sehingga nilai a bisa di akses oleh *ptr. fungsi tukar() menerima alamt a dan b lalu menukar nilainya.

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
Program ini menggunakan reference untuk menukar nilai dua variabel. Reference (ref) berfungsi sebagai alias dari variabel a, sehingga perubahan pada ref juga mengubah a. Fungsi tukar() menukar nilai a dan b tanpa menggunakan pointer.
.

## Unguided 

### 1. [Matrix 3x3]

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3],
    C[3][3];

    cout << "Buat Matrix A:\n";
    for (int i =0; i < 3; i++){
        for (int j=0; j < 3; j++){
            cin >> A[i][j];
        }
        cout << endl;
    }

    cout << "Buat Matrix B:\n";
    for (int i =0; i < 3; i++){
        for (int j =0; j < 3; j++){
            cin >> B[i][j];
        }
        cout << endl;
    }
        cout << "\nHasil Penjumlahan:\n";
        for (int i =0; i < 3; i++){
            for (int j =0; j < 3; j++){
                cout << A[i][j] + B[i][j] << "\t";
            }
            cout << endl;
        } 

        cout << "\nHasil Pengurangan:\n";
        for (int i=0; i < 3; i++) {
            for (int j =0; j < 3; j++) {
                cout << A[i][j] - B[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nHasil Perkalian:\n";
        for (int i=0; i < 3; i++) {
            for (int j=0; j < 3; j++) {
                C[i][j] = 0;
                for (int k=0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }

    return 0;
}
```
#### Output:
<img width="1369" height="604" alt="image" src="https://github.com/user-attachments/assets/efcfc967-8dce-41c0-84fd-d2be24734325" />

Program ini dibuat untuk melakukan operasi dasar penjumlahan, pengurangan dan perkalian terhadap 2 buah matrix dengan ukuran 3x3, program akan meminta input untuk kedua matrix yang akan di lakukan operasi dasar, lalu program akan melanjutkan ke proses operasi dasar yang sudah di buat lalu hasil akan di simpan di matrix C, output nya bentuk matrix 3x3 dengan hasil dari masing masing operasi dasar.

#### Full code Screenshot:
<img width="1919" height="1057" alt="image" src="https://github.com/user-attachments/assets/1f4d4841-3728-41f9-9b24-fc54d933897e" />


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
