#include "ListIkan.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi("Lele", 2.5, 20000));
    insertLast(L, alokasi("Gurame", 1.2, 35000));
    insertLast(L, alokasi("Patin", 3.0, 25000));
    insertLast(L, alokasi("Nila", 2.0, 30000));

    cout << "=== Data Ikan Hasil Pancingan ===" << endl;
    printInfo(L);

    cout << "\nCari ikan 'Patin':" << endl;
    address cari = findIkan(L, "Patin");
    if (cari != Nil)
        cout << "Ikan ditemukan! Berat: " << cari->info.berat << " kg, Harga/kg: " << cari->info.harga << endl;
    else
        cout << "Ikan tidak ditemukan." << endl;

    cout << "\nUpdate ikan 'Lele' jadi berat 3 kg dan harga 22000/kg" << endl;
    updateIkan(L, "Lele", 3.0, 22000);

    cout << "\n=== Data Setelah Update ===" << endl;
    printInfo(L);

    int total = totalHarga(L);
    cout << "\nTotal harga semua ikan: Rp " << total << endl;

    return 0;
}
