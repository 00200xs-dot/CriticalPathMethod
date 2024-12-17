#include <find.h>

void findCriticalActivities(Graph *G, int *Ve, int *Vl) {
    for (int i = 0; i < G->nums; i++) {
        EdgeNode *temp = G->list[i].firstedge;
        while (temp != NULL) {
            int ee = Ve[i];
            int el = Vl[temp->adjvex] - temp->val;
            if (ee == el) {
                printf("�(V%d -> V%d)�ǹؼ����Ȩ��Ϊ: %d \n", i + 1, temp->adjvex + 1, temp->val);
            }
            temp = temp->next;
        }
    }
}
