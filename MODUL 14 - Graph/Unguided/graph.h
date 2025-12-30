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
