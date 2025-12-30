#ifndef BSTREE_H
#define BSTREE_H
#define NIL NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// ADT BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void InOrder(address root);

// latihan tambahan
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif
