#include "soalstack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    cout << "Masukkan input: ";
    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}
