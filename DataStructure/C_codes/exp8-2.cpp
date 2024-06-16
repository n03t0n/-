#include "traversal.cpp"
int main()
{
    AdjGraph *G;
    int A[MAXV][MAXV] = {
        {0, 5, INF, 7, INF, INF, INF},
        {0, 4, INF, INF, INF, INF, INF},
        {8, INF, INF, INF, 9, 5, 0},
        {INF, INF, 5, INF, 0, INF, 6},
        {INF, INF, INF, 5, INF, 3, 0},
        {7, INF, INF, INF, 1, INF, 0}
    };
    int n = 6, e = 6; //图 8.1 的邻接矩阵
    CreateAdj(G, A, n, e); //创建邻接表
    printf("图的邻接表:\n"); DispAdj(G); //输出邻接表
    printf("递归的深度优先搜索:\n");
    DFS(G, 0); printf("\n");
    printf("非递归的深度优先搜索:\n");
    DFS1(G, 0); printf("\n");
    printf("广度优先搜索:\n");
    BFS(G, 0); printf("\n");
    DestroyAdj(G); //销毁邻接表
    return 1;
}
