#include <stdio.h>
#include <malloc.h>
#define INF 32767 //定义∞
#define MAXV 100 //最大顶点个数
typedef char InfoType;
//以下定义邻接矩阵类型
typedef struct
{
    int no; //顶点编号
    InfoType info; //顶点其他信息
} VertexType;
typedef struct
{
    int edges[MAXV][MAXV]; //邻接矩阵数组
    int n, e; //顶点数，边数
    VertexType vexs[MAXV]; //顶点信息
} MatGraph;

//以下定义邻接表类型
typedef struct ANode
{
    int adjvex; //该边的邻接点编号
    struct ANode *nextarc; //指向下一条边的指针
    int weight; //该边的相关信息, 如权值 (用指针表示)
} ArcNode;
typedef struct VNode
{
    InfoType info; //顶点其他信息
    int count; //存放入度, 仅在用于拓扑排序时用
    ArcNode *firstarc; //指向第一条边
} VNode, AdjList[MAXV]; //VNode类型定义顶点表类型
typedef struct
{
    AdjList adjlist; //邻接表
    int n, e; //顶点数，边数
} AdjGraph;

//----------------------------
//邻接矩阵的基本运算算法
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e) //创建图的邻接矩阵
{
    int i, j;
    g.n = n; g.e = e;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = A[i][j];
}

void DispMat(MatGraph g) //输出邻接矩阵 g
{
    int i, j;
    for (i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] != INF)
                printf("%2d", g.edges[i][j]);
            else
                printf("%4s", "∞");
        printf("\n");
    }
}

//----------------------------
//邻接表的基本运算算法
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) //创建图的邻接表
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++)
        G->adjlist[i].firstarc = NULL; //给邻接表中所有顶点的指针域初始化为空
    for (i = 0; i < n; i++)
        for (j = n - 1; j >= 0; j--)
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode *) malloc(sizeof(ArcNode)); //存在一条边
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc; //将 p 插入表头
                G->adjlist[i].firstarc = p;
            }
    G->n = n; G->e = e;
}

void DispAdj(AdjGraph *G) //输出邻接表 G
{
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("%3d[%d] ", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("\n");
    }
}

void DestroyAdj(AdjGraph *&G) //销毁图的邻接表
{
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjlist[i].firstarc;
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL)
            {
                free(pre);
                pre = p; p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}
