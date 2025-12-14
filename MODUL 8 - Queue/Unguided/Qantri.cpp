#include "Qantri.h"

void createQueue(Queue &Q) {
    Q.head = NIL;
    Q.tail = NIL;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == NIL;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = NIL;
        Q.tail = NIL;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "   | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << "";
        }
    }
   cout << endl;
}
