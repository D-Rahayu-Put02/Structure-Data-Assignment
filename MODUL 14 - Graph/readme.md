# <h1 align="center">Laporan Praktikum Modul 14 Graph </h1>
<p align="center">Dwi Rahayu Putra</p>

## Dasar Teori
- Pengertian Graph

Graph merupakan himpunan tidak kosong dari node (vertex) dan garis penghubung (edge) yang merepresentasikan hubungan antar objek. Contoh sederhana graph adalah hubungan antara Tempat Kost dan Common Lab, di mana Tempat Kost dan Common Lab berperan sebagai node, sedangkan jalan yang menghubungkan keduanya merupakan edge.

Selain itu, graph dapat digunakan untuk memodelkan berbagai permasalahan nyata seperti peta jalan, jaringan komputer, hubungan pertemanan, dan alur komunikasi, sehingga sangat berguna dalam pemodelan struktur data yang kompleks.

## Guided

### 1. [grap.h]

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;         // Menyimpan data node (misal: char/int)
    int visited;            // Penanda untuk traversal (0/1)
    adrEdge firstEdge;      // Pointer ke edge pertama yang terhubung
    adrNode Next;           // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;           // Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;           // Pointer ke edge berikutnya
};

struct Graph {
    adrNode First;          // Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);                         // Set first = NULL
adrNode AlokasiNode(infoGraph data);                // Alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);            // Alokasi edge baru

void InsertNode(Graph &G, infoGraph data);          // Menambahkan node
adrNode FindNode(Graph G, infoGraph data);         // Mencari node
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);                  // Menghubungkan node
void DisconnectNode(Graph &G, infoGraph info1, infoGraph info2);               // Memutus hubungan node
void DeleteNode(Graph &G, infoGraph X);             // Menghapus node dan edge

void PrintInfoGraph(Graph G);                       // Menampilkan adjacency list
void ResetVisited(Graph &G);                        // Reset visited
void PrintBFS(Graph G, infoGraph StartInfo);        // Traversal BFS
void PrintDFS(Graph G, infoGraph StartInfo);        // Traversal DFS

#endif
```
graph.h berisi pendefinisian struktur data graph yaitu (node, edge dan graph) serta deklarasi fungsi-fungsi dasar seperti insert node, connect node, delete node dan traversal BFS-DFS.

### 2. [graph.cpp]

```C++
#include "Graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```
graph.cpp berisi implementasi seluruh fungsi graph, termasuk pembuatan graph, penghubungan node secara undirected, penghapusan node berserta edgenya, serta traversal BFS dan DFS.

### 3. [main.cpp]

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

    return 0;
}
```
main.cpp digunakan untuk menguji program dengan membuat graph, menghubungkan node, menampilkan adjacency list, melakukan traversal, dan menghapus node.

## Unguided 
### 1. [graph.h]

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmEdge {
    adrNode node;
    adrEdge next;
};

struct elmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode createNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
adrNode findNode(Graph G, infoGraph x);
void connectNode(adrNode N1, adrNode N2);
void printInfoGraph(Graph G);

void printDFS(Graph &G, adrNode N);
void printBFS(Graph G, adrNode N);

#endif
```
### 2. [graph.cpp]
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode createNode(infoGraph x) {
    adrNode P = new elmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = createNode(x);
    P->next = G.first;
    G.first = P;
}

adrNode findNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == x)
            return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new elmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new elmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void printInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void printDFS(Graph &G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->info << " ";
        N->visited = 1;
        adrEdge E = N->firstEdge;
        while (E != NULL) {
            printDFS(G, E->node);
            E = E->next;
        }
    }
}

void printBFS(Graph G, adrNode N) {
    adrNode Q[20];
    int front = 0, rear = 0;

    Q[rear++] = N;
    N->visited = 1;

    while (front < rear) {
        adrNode P = Q[front++];
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q[rear++] = E->node;
            }
            E = E->next;
        }
    }
}
```
### 3. [main.cpp]

```C++
#include "graph.h"

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    connectNode(findNode(G,'A'), findNode(G,'B'));
    connectNode(findNode(G,'A'), findNode(G,'C'));
    connectNode(findNode(G,'B'), findNode(G,'D'));
    connectNode(findNode(G,'B'), findNode(G,'E'));
    connectNode(findNode(G,'C'), findNode(G,'F'));
    connectNode(findNode(G,'C'), findNode(G,'G'));
    connectNode(findNode(G,'D'), findNode(G,'H'));
    connectNode(findNode(G,'E'), findNode(G,'H'));
    connectNode(findNode(G,'F'), findNode(G,'H'));
    connectNode(findNode(G,'G'), findNode(G,'H'));

    cout << "DFS : ";
    printDFS(G, findNode(G,'A'));
    cout << endl;

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    cout << "BFS : ";
    printBFS(G, findNode(G,'A'));
    cout << endl;

    return 0;
}
```

#### Output:
<img width="1451" height="70" alt="image" src="https://github.com/user-attachments/assets/765cb6b8-d08d-468e-99e2-5ac8046d6ed2" />


Program ini dibuat untuk mengelola data kendaraan menggunakan Doubly Linked List.
Setiap node menyimpan nomor polisi, warna kendaraan, dan tahun pembuatan.
Program dapat melakukan:
- menambah data kendaraan ke belakang list (insertLast)
- menampilkan seluruh data (printInfo)
- mengecek apakah nopol sudah terdaftar (findElm)
- mencari data kendaraan tertentu
- menghapus data berdasarkan posisi (deleteFirst, deleteLast, deleteAfter)
- menolak input kendaraan dengan nopol yang sama (duplikasi)
Program ini mensimulasikan cara kerja struktur data Double Linked List untuk pengolahan data kendaraan secara dinamis.
#### Full code Screenshot:
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/9312ae5c-1ac7-4f28-ad23-b16838bdda48" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/8b0a9cc4-cbef-4ac2-af93-7312eaee681c" />

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/2151f9d8-4adb-4d56-9ba6-646defe68845" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalian dari hasil praktikum dan pembelajaran yang didapat[1]. Modul 14 pada modul ini materi yang di sampaikan itu tentang Graph, 


## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar
