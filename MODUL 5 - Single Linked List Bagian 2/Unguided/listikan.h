#ifndef LISTIKAN_H
#define LISTIKAN_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct ikan {
    string nama;
    float berat;
    int harga; 
};

typedef ikan infotype;
typedef struct Node *address;

struct Node{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
bool isEmpty(List L);
address alokasi(string nama, float berat, int harga);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findIkan(List L, string nama);
void updateIkan(List &L, string namaCari, float beratBaru, int hargaBaru);
int totalHarga(List L);

#endif
