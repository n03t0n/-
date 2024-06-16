#include "graph.cpp"     //包含图的存储结构及基本运算算法
void Dispath(MatGraph g, int dist[], int path[], int S[], int v)
//输出从顶点 v 出发的所有最短路径
{
    int i, j, k;
    int apath[MAXV], d;    //存放一条最短路径(逆向)及其顶点个数
    for (i = 0; i < g.n; i++)
        if (S[i] == 1 && i != v)
        {
            printf("从顶点 %d 到顶点 %d 的路径长度为: %d\n 路径为:", v, i, dist[i]);
            d = 0; apath[d] = i;     //添加路径的终点
            k = path[i];
            if (k == -1)             //没有路径的情况
                printf("无路径\n");
            else
            {
                while (k != v)
                {
                    d++; apath[d] = k;
                    k = path[k];
                }
                d++; apath[d] = v;   //添加路径的起点
                printf("%d", apath[d]);
                for (j = d - 1; j >= 0; j--)
                    printf(" %d", apath[j]);
                printf("\n");
            }
        }
}

void Dijkstra(MatGraph g, int v)
//Dijkstra 算法
{
    int dist[MAXV], path[MAXV];   //S[i] = 1 表示顶点 i 在 S 中, S[i] = 0 表示顶点 i 在 U 中
    int S[MAXV];
    int Mindis, i, j, u;
    for (i = 0; i < g.n; i++)     //距离初始化
    {
        dist[i] = g.edges[v][i];
        S[i] = 0;                 //S[i] 置空
        if (g.edges[v][i] < INF)  //路径初始化
            path[i] = v;          //顶点 v 到顶点 i 有边时, 置顶点 i 的前一个顶点为 v
        else
            path[i] = -1;         //顶点 v 到顶点 i 没边时, 置顶点 i 的前一个顶点为 -1
    }
    S[v] = 1; path[v] = 0;        //源点编号 v 放入 S 中
    for (i = 0; i < g.n - 1; i++) //循环直到所有顶点的最短路径都求出
    {
        Mindis = INF;             //Mindis 置最大长度初值
        for (j = 0; j < g.n; j++) //选取不在 S 中(即 U 中)且具有最小最短路径长度的顶点 u
            if (S[j] == 0 && dist[j] < Mindis)
            {
                u = j;
                Mindis = dist[j];
            }
        S[u] = 1;                 //顶点 u 加入 S 中
        for (j = 0; j < g.n; j++) //修改不在 S 中(即 U 中)的顶点的最短路径
            if (S[j] == 0)
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j])
                {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
    }
    Dispath(g, dist, path, S, v); //输出最短路径
}

int main()
{
    int v = 0;
    MatGraph g;
    int A[MAXV][MAXV] = {
        {0, 5, INF, 7, INF, 9}, 
        {5, 0, 4, INF, INF, INF}, 
        {8, 4, 0, INF, 5, 6}, 
        {INF, INF, 5, 0, INF, 1}, 
        {3, INF, 9, 6, 1, 0}
    };
    int n = 6, e = 10;
    CreateMat(g, A, n, e);   //建立图 8.1 的邻接矩阵
    printf("有向图 G 的邻接矩阵:\n"); DispMat(g);
    printf("狄克斯特拉算法求解结果:\n");
    Dijkstra(g, v);
    return 1;
}
