#include <sort.h>
#include <Stack.h>

int TopologicalSort(const Graph *G, int *Ve) {
    //初始化入度数组
    int *Indegree = malloc(sizeof(int) * G->nums); //入度数组
    for (int i = 0; i < G->nums; i++) {
        Indegree[i] = 0;
    }
    //计算入度
    for (int i = 0; i < G->nums; i++) {
        EdgeNode *temp = G->list[i].firstedge;
        while (temp != NULL) {
            ++Indegree[temp->adjvex];
            temp = temp->next;
        }
    }
    //初始化栈 将入度为0的节点压入栈内
    stack S = {-1, (int *) malloc(sizeof(int) * G->nums)};
    for (int i = 0; i < G->nums; i++) {
        if (Indegree[i] == 0) {
            S.data[++S.top] = i;
        }
    }

    int count = 0; //计数
    for (int i = 0; i < G->nums; i++) {
        Ve[i] = 0;
    } //初始化最早发生时间

    while (S.top != -1) {
        int v = S.data[S.top--];
        ++count;
        EdgeNode *temp = G->list[v].firstedge;
        while (temp != NULL) {
            int k = temp->adjvex;
            if (--Indegree[k] == 0) {
                S.data[++S.top] = k;
            }
            if (Ve[v] + temp->val > Ve[k]) {
                Ve[k] = Ve[v] + temp->val;
            }
            temp = temp->next;
        }
    }
    free(Indegree);
    free(S.data);

    if (count == G->nums)
        return 0; // 无环
    return 1; //有环
}

//计算最晚发生时间

void calculateLatest(const Graph *G, int *Ve, int *Vl) {
    for (int i = 0; i < G->nums; i++) {
        Vl[i] = Ve[G->nums - 1];
    }

    for (int i = G->nums - 1; i >= 0; i--) {
        EdgeNode *temp = G->list[i].firstedge;
        while (temp != NULL) {
            if (Vl[temp->adjvex] - temp->val < Vl[i]) {
                Vl[i] = Vl[temp->adjvex] - temp->val;
            }
            temp = temp->next;
        }
    }
}
