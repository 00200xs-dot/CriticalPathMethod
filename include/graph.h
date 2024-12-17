#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<stdlib.h>

typedef struct EdgeNode {
    int adjvex; //目标节点下标
    int val;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
    int data;
    EdgeNode *firstedge;
} VertexNode;

typedef struct Graph {
    int nums; //节点数量
    VertexNode *list;
} Graph;

//初始化图
Graph *initgraph(int verticesNums);

//添加新边
void addEdge(const Graph *G,  int start,  int end, int val);

#endif //GRAPH_H
