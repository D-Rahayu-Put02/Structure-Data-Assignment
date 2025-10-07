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
