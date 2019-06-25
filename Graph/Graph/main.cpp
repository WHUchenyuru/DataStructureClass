//图：实现有（无）向、（带权）不带权图的构建（要求使用邻接表和邻接矩阵）、遍历图
#include "CircularQueue.hpp"
#include <iostream>
#include <stdio.h>
#define MAXV 100
#define INF 32767   //定义正无穷

//无(有)向带权图图邻接表
typedef struct ANode
{
    int adjvex;             //该边的邻接点编号
    struct ANode * nextrac; //指向下一条边的指针
    int weight;             //该边的权值
}ArcNode;                   //边结点类型

typedef struct VNode
{
    int info;               //头结点编号
    ArcNode * firstarc;     //指向第一个边结点
}VNode;                     //头结点类型

typedef struct
{
    VNode adjlist[MAXV];    //邻接表的头结点数组
    int n , e;              //图中的顶点数和边数
}AdjGraph;

//无(有)向带权图的邻接矩阵表示法
typedef struct
{
    int no;         //顶点的编号
}VertexType;        //顶点的类型

typedef struct
{
    int edges[MAXV][MAXV];  //邻接矩阵数组
    int n , e;              //顶点数、边数
    VertexType vexs[MAXV];  //存放顶点信息
}MatGraph;                  //完整的图邻接矩阵类型

//根据邻接矩阵数组A、顶点个数n、边数e建立图的邻接表
void CreateAdj(AdjGraph *& G, int A[MAXV][MAXV], int n, int e)
{
    int i , j; ArcNode * p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph ));
    for(i = 0; i < n; i++)      //给邻接表中所有头结点的指针域置初值
    {
        G->adjlist[i].firstarc = NULL;
    }
    for(i = 0; i < n; i++)          //检查邻接矩阵中的每个元素
        for(j = n - 1; j >= 0; j--)
            if(A[i][j] != 0 && A[i][j] != INF)  //存在一条边
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));     //创建一个结点p
                p->adjvex = j;                              //存放邻接点
                p->weight = A[i][j];                        //存放权重
                p->nextrac = G->adjlist[i].firstarc;        //采用头插法插入结点p
                G->adjlist[i].firstarc = p;
            }
    G->n = n ; G->e = e;
}

//创建图的邻接矩阵
void CreateMat(MatGraph & g, int A[MAXV][MAXV], int n, int e)
{
    int i , j;
    g.n = n ; g.e = e;
    for(i = 0 ; i < g.n; i++)
        for(j = 0 ; j < g.n ; j++)
            g.edges[i][j] = A[i][j];
}

//深度优先遍历
int visited[MAXV] = {0};        //全局数组
void DFS(AdjGraph * G , int v)  //v是起始点
{
    ArcNode * p;
    visited[v] = 1;             //置已访问标记
    printf("%2d" , v);           //输出已被访问的顶点编号
    p = G->adjlist[v].firstarc; //p指向顶点v的第一个邻接点
    while(p != NULL)
    {
        if(visited[p->adjvex] == 0) //如果p->adjvex顶点未被访问，递归访问他
            DFS(G , p->adjvex);
        p = p->nextrac;             //p指向顶点v的下一个邻接点
    }
}

//广度优先遍历
void BFS(AdjGraph * G , int v)
{
    int w , i;  ArcNode * p;
    CirQueue * qu;          //定义环形队列指针
    InitCirQueue(qu);
    for(i = 0 ; i < G->n ; i++)
        visited[i] = 0;
    printf("%2d" , v);      //输出被访问顶点的编号
    visited[v] = 1;
    enCirQueue(qu, v);
    while(!CirQueueEmpty(qu))   //队不空循环
    {
        deCirQueue(qu, w);      //出队一个顶点w
        p = G->adjlist[w].firstarc; //指向w的第一个邻接点
        while(p != NULL)            //查找w的所有邻接点
        {
            if(visited[p->adjvex] == 0) //若当前邻接点未被访问
            {
                printf("%2d" , p->adjvex);
                visited[p->adjvex] = 1;     //置已访问标记
                enCirQueue(qu, p->adjvex);  //该顶点进队
            }
            p = p->nextrac;
        }
    }
    printf("\n");
}


int main() {
    int n = 5 , e = 5;
    int A[MAXV][MAXV] = {{0 , 8 , INF , 5 , INF},
        {INF , 0 , 3 , INF , INF}, {INF , INF , 0 , INF , 6},
        {INF , INF , 9 , 0 , INF}, {INF , INF , INF , INF , 0}
    };
    AdjGraph * G;  MatGraph g;
    CreateAdj(G, A, n, e);
    CreateMat(g, A, n, e);
    printf("深度优先：\n");
    DFS(G, 0);
    printf("\n");
    printf("广度优先：\n");
    BFS(G, 0);
    return 0;
}
