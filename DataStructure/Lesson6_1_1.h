/*图*/
#define MaxVertexNum 10
typedef int WeightType;
typedef int DataType;
typedef int Vertex;
typedef struct ENode* PtrToENode;
//边
struct ENode {
	Vertex V1, V2;//相互连接的两节点
	WeightType Weight;//权重
};
typedef PtrToENode Edge;//边

/*----------------邻接矩阵-----------------*/
typedef struct AdjMatrixGNode* PtrToAdjMatrixGNode;

//邻接矩阵顶点
struct AdjMatrixGNode {
	int Nv;//顶点数
	int Ne;//边数
	WeightType G[MaxVertexNum][MaxVertexNum];//权重,G[v][m]大于0表示可以从v走到m
	DataType Data[MaxVertexNum];//数值
};

typedef PtrToAdjMatrixGNode MGraph;//顶点

//建立邻接矩阵
MGraph CreateAdjMatrix(int VertexNum);
//将v插入G
MGraph InsertVertex(MGraph Graph, Vertex V);
//将e插入G
MGraph InsertEdge(MGraph Graph, Edge E);
//从顶点v出发深度优先遍历图G
void DFS(MGraph Graph, Vertex v);
//从顶点v出发宽度优先遍历图G
void BFS(MGraph Graph, Vertex v);
//计算图G中顶点v到任意其他顶点的最短距离
void ShortestPath(MGraph Graph, Vertex v, int Dist[]);
//计算图G的最小生成树
void MST(MGraph Graph);

/*----------------邻接表-----------------*/
typedef struct AdjTableGNode* PtrToAdjTableGNode;
typedef struct AdjVNode* PtrToAdjTableVNode;

//邻接表
struct AdjTableGNode {
	int Nv; //顶点数
	int Ne;//边数
	AdjList G;//邻接表
};

//邻接节点
typedef struct VNode {
	PtrToAdjTableVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];//AdjList 邻接表类型

//节点链接
typedef struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjTableVNode Next;
};

typedef PtrToAdjTableGNode TGraph;//邻接节点

//建立邻接矩阵
TGraph CreateAdjTable(int VertexNum);
//将v插入G
TGraph InsertVertex(TGraph Graph, Vertex v);
//将e插入G
TGraph InsertEdge(TGraph Graph, Edge E);
//从顶点v出发深度优先遍历图G
void DFS(TGraph Graph, Vertex v);
//从顶点v出发宽度优先遍历图G
void BFS(TGraph Graph, Vertex v);
//计算图G中顶点v到任意其他顶点的最短距离
void ShortestPath(TGraph Graph, Vertex v, int Dist[]);
//计算图G的最小生成树
void MST(TGraph Graph);

/*----------------执行-----------------*/
//创建邻接矩阵图
MGraph BuildAdjMatricGraph();
//创建邻接矩阵图
TGraph BuildAdjTableGraph();