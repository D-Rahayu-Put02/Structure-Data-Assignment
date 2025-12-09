#ifndef SOALSTACK_H
#define SOALSTACK_H
#define MAX 20
#define NIL -1
#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// fungsi untuk nomor 2
void pushAscending(Stack &S, infotype x);

// fungsi untuk nomor 3
void getInputStream(Stack &S);

#endif
