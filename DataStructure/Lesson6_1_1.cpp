#include "Lesson6_1_1.h"
#include <stdio.h>
#include <iostream>

MGraph CreateAdjMatrix(int VertexNum)
{
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct AdjMatrixGNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    // 从0至 Graph->Nv -1
    for (V = 0; V < Graph->Nv; V++)
    {
        for (size_t W = 0; W < Graph->Nv; W++)
        {
            Graph->G[V][W] = 0;//或INFINITY
        }
    }

    return Graph;
}

MGraph InsertVertex(MGraph Graph, Vertex V)
{
    if (V <= 0)
        return Graph;
    for (Vertex i = 0; i < V-1; i++)
    {
        Graph->G[i][V] = 0;
        Graph->G[V][i] = 0;
    }
    Graph->G[V - 1][V - 1] = 0;
    Graph->Nv++;
    return Graph;
}

MGraph InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;//插入边<V1,V2>
    Graph->G[E->V2][E->V1] = E->Weight;//无向图还需增加<V2,V1>
    Graph->Ne++;
}

void DFS(MGraph Graph, Vertex v)
{
    Graph->G[V] = true;
    for (V 的每个邻接点 W)
        if (!visited[W])
            DFS(W);
}

void BFS(MGraph Graph, Vertex v)
{
        visited[V] = true;
        Enqueue(V, Q);
        while (!IsEmpty(Q)) {
            V = Dequeue(Q);
            for (V 的每个邻接点 W)
                if (!visited[W]) {
                    visited[W] = true;
                    Enqueue(W, Q);
                }
        }
}

void ShortestPath(MGraph Graph, Vertex v, int Dist[])
{
}

void MST(MGraph Graph)
{
}

TGraph CreateAdjTable(int VertexNum)
{
    Vertex V, W;
    TGraph Graph;

    Graph = (TGraph)malloc(sizeof(struct AdjTableGNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    // 从0至 Graph->Nv -1
    for (V = 0; V < Graph->Nv; V++)
    {
        Graph->G[V].FirstEdge = NULL;
    }

    return Graph;
}

TGraph InsertVertex(TGraph Graph, Vertex v)
{
    return TGraph();
}

TGraph InsertEdge(TGraph Graph, Edge E)
{
    PtrToAdjTableVNode NewNode;

    //插入边<V1,V2>
    //为V2建立新的邻接点
    NewNode = (PtrToAdjTableVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    //将V2插入V1的表头
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //若为无向图，需要插入<V2,V1>
    NewNode = (PtrToAdjTableVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    //将V2插入V1的表头
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;

    return Graph;
}

void DFS(TGraph Graph, Vertex v)
{
}

void BFS(TGraph Graph, Vertex v)
{
}

void ShortestPath(TGraph Graph, Vertex v, int Dist[])
{
}

void MST(TGraph Graph)
{
}


//Invoke
MGraph BuildAdjMatricGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    scanf("%d", &Nv);
    Graph = CreateAdjMatrix(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for (size_t i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    for (V = 0; V < Graph->Nv; V++)
    {
        scanf("  %d", &(Graph->Data[V]));
    }
    return Graph;
}

TGraph BuildAdjTableGraph()
{
    TGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;
    scanf("%d", &Nv);
    Graph = CreateAdjTable(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for (size_t i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    for (V = 0; V < Graph->Nv; V++)
    {
        scanf("  %d", &(Graph->G[V]));
    }
    return Graph;
}

