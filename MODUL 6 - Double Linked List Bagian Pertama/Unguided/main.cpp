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
