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
