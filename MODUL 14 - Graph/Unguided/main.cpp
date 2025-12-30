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
