#include "bstree.h"

// Alokasi node
address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NIL;
    P->right = NIL;
    return P;
}

// Insert BST
void insertNode(address &root, infotype x) {
    if (root == NIL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

// Cari node
address findNode(address root, infotype x) {
    if (root == NIL || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(root->left, x);
    } else {
        return findNode(root->right, x);
    }
}

// Traversal InOrder
void InOrder(address root) {
    if (root != NIL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

// Hitung jumlah node
int hitungJumlahNode(address root) {
    if (root == NIL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Hitung total nilai info
int hitungTotalInfo(address root) {
    if (root == NIL) {
        return 0;
    }
    return root->info +
           hitungTotalInfo(root->left) +
           hitungTotalInfo(root->right);
}

// Hitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == NIL) {
        return start;
    }

    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);

    return (kiri > kanan) ? kiri : kanan;
}
