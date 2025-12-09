#include "soalstack.h"

void createStack(Stack &S) {
    S.top = NIL;
}

void push(Stack &S, infotype x) {
    if (S.top == MAX - 1) return;
    S.top++;
    S.info[S.top] = x;
}

infotype pop(Stack &S) {
    if (S.top == NIL) return -999; 
    infotype x = S.info[S.top];
    S.top--;
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top != NIL) {
        push(temp, pop(S));
    }

    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    if (S.top == MAX - 1) return;

    Stack temp;
    createStack(temp);

    while (S.top != NIL && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top != NIL) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char c;
    while (true) {
        c = cin.get();
        if (c == '\n') break;
        int x = c - '0';  
        if (x >= 0 && x <= 9) {
            push(S, x);
        }
    }
}
