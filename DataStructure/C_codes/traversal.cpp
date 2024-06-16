#include "graph.cpp" //包含图的存储结构及基本运算算法
int visited[MAXV]; //全局数组
void DFS(AdjGraph *G, int v) //递归深度优先遍历算法
{
    ArcNode *p;
    printf("%3d", v); visited[v] = 1; //访问顶点 v，并置已访问标记
    p = G->adjlist[v].firstarc; //p 指向顶点 v 的第一条边
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0) //若顶点未访问过,递归访问它
            DFS(G, p->adjvex);
        p = p->nextarc; //找顶点 v 的下一条边的另一个顶点
    }
}

void DFS1(AdjGraph *G, int v) //非递归深度优先遍历算法
{
    int St[MAXV];
    ArcNode *p;
    int top = -1, w, i;
    for (i = 0; i < G->n; i++) visited[i] = 0; //顶点访问标记数组初始化
    top++; St[top] = v; visited[v] = 1; //顶点 v 入栈
    printf("%3d", v);
    while (top > -1) //栈不空时循环
    {
        w = St[top]; //取栈顶顶点
        p = G->adjlist[w].firstarc; //找顶点的第一条边
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0) //若顶点未访问过
            {
                St[++top] = p->adjvex; //顶点入栈
                printf("%3d", p->adjvex);
                visited[p->adjvex] = 1; //置已访问标记
                break; //退出循环, 即再处理栈顶的顶点 (体现后进先出)
            }
            p = p->nextarc; //找顶点的下一个相邻点
        }
        if (p == NULL) top--; //若顶点 w 没有相邻点, 将其退栈
    }
    printf("\n");
}

void BFS(AdjGraph *G, int v) //广度优先遍历算法
{
    ArcNode *p;
    int queue[MAXV], front = 0, rear = 0;
    int visited[MAXV];
    for (int i = 0; i < G->n; i++) visited[i] = 0; //访问标记数组初始化
    printf("%3d", v); visited[v] = 1; //访问顶点 v 并置访问标记
    rear = (rear + 1) % MAXV;
    queue[rear] = v; //顶点 v 入队列
    while (front != rear)
    {
        front = (front + 1) % MAXV;
        v = queue[front]; //出队并访问
        p = G->adjlist[v].firstarc; //找顶点 v 的第一个相邻点
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0) //相邻顶点未访问过
            {
                printf("%3d", p->adjvex);
                visited[p->adjvex] = 1; //置已访问标记
                rear = (rear + 1) % MAXV;
                queue[rear] = p->adjvex; //相邻顶点入队列
            }
            p = p->nextarc; //找下一个相邻点
        }
    }
    printf("\n");
}

