#include <stdio.h>
#include <find.h>
#include <sort.h>

int main() {
    Graph *G = initgraph(6);
    int *Ve = malloc(G->nums * sizeof(int)); //最早发生时间
    int *Vl = malloc(G->nums * sizeof(int)); //最晚发生时间

    addEdge(G, 0, 1, 3);
    addEdge(G, 0, 2, 2);
    addEdge(G, 1, 4, 3);
    addEdge(G, 1, 3, 2);
    addEdge(G, 2, 3, 4);
    addEdge(G, 2, 5, 3);
    addEdge(G, 3, 5, 2);
    addEdge(G, 4, 5, 1);

    const int t = TopologicalSort(G, Ve);
    if (t) {
        printf("图中存在环\n");
    } else {
        printf("图中无环\n");
        calculateLatest(G, Ve, Vl);
        findCriticalActivities(G, Ve, Vl);
    }
    return 0;
}
