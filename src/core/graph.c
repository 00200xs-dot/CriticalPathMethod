#include <graph.h>

Graph *initgraph(const int verticesNums) {
    Graph *G = malloc(sizeof(Graph));
    G->nums = verticesNums;
    G->list = (VertexNode *) malloc(sizeof(VertexNode) * verticesNums);
    for (int i = 0; i < verticesNums; i++) {
        G->list[i].data = i; //顶点编号1, 2, 3 ......
        G->list[i].firstedge = NULL; //初始化链表为空
    }
    return G;
}

void addEdge(const Graph *G, const int start, const int end, const int val) {
    EdgeNode *newedge = malloc(sizeof(EdgeNode));
    newedge->adjvex = end; //新边的目标节点
    newedge->val = val;
    newedge->next = G->list[start].firstedge;
    G->list[start].firstedge = newedge; //头插法插入 更新相连链表
}
