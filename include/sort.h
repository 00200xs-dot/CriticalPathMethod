#ifndef SORT_H
#define SORT_H

#include <graph.h>

//拓扑排序 计算最早完成时间Ve
int TopologicalSort(const Graph *G, int *Ve);
//逆拓扑排序 计算最晚完成时间Vl
void calculateLatest(const Graph *G, int *Ve,int* Vl);

#endif //SORT_H
