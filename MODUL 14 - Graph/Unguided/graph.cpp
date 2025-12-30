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
