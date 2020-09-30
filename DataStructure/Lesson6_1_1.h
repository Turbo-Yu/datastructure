/*ͼ*/
#define MaxVertexNum 10
typedef int WeightType;
typedef int DataType;
typedef int Vertex;
typedef struct ENode* PtrToENode;
//��
struct ENode {
	Vertex V1, V2;//�໥���ӵ����ڵ�
	WeightType Weight;//Ȩ��
};
typedef PtrToENode Edge;//��

/*----------------�ڽӾ���-----------------*/
typedef struct AdjMatrixGNode* PtrToAdjMatrixGNode;

//�ڽӾ��󶥵�
struct AdjMatrixGNode {
	int Nv;//������
	int Ne;//����
	WeightType G[MaxVertexNum][MaxVertexNum];//Ȩ��,G[v][m]����0��ʾ���Դ�v�ߵ�m
	DataType Data[MaxVertexNum];//��ֵ
};

typedef PtrToAdjMatrixGNode MGraph;//����

//�����ڽӾ���
MGraph CreateAdjMatrix(int VertexNum);
//��v����G
MGraph InsertVertex(MGraph Graph, Vertex V);
//��e����G
MGraph InsertEdge(MGraph Graph, Edge E);
//�Ӷ���v����������ȱ���ͼG
void DFS(MGraph Graph, Vertex v);
//�Ӷ���v����������ȱ���ͼG
void BFS(MGraph Graph, Vertex v);
//����ͼG�ж���v�����������������̾���
void ShortestPath(MGraph Graph, Vertex v, int Dist[]);
//����ͼG����С������
void MST(MGraph Graph);

/*----------------�ڽӱ�-----------------*/
typedef struct AdjTableGNode* PtrToAdjTableGNode;
typedef struct AdjVNode* PtrToAdjTableVNode;

//�ڽӱ�
struct AdjTableGNode {
	int Nv; //������
	int Ne;//����
	AdjList G;//�ڽӱ�
};

//�ڽӽڵ�
typedef struct VNode {
	PtrToAdjTableVNode FirstEdge;
	DataType Data;
} AdjList[MaxVertexNum];//AdjList �ڽӱ�����

//�ڵ�����
typedef struct AdjVNode {
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjTableVNode Next;
};

typedef PtrToAdjTableGNode TGraph;//�ڽӽڵ�

//�����ڽӾ���
TGraph CreateAdjTable(int VertexNum);
//��v����G
TGraph InsertVertex(TGraph Graph, Vertex v);
//��e����G
TGraph InsertEdge(TGraph Graph, Edge E);
//�Ӷ���v����������ȱ���ͼG
void DFS(TGraph Graph, Vertex v);
//�Ӷ���v����������ȱ���ͼG
void BFS(TGraph Graph, Vertex v);
//����ͼG�ж���v�����������������̾���
void ShortestPath(TGraph Graph, Vertex v, int Dist[]);
//����ͼG����С������
void MST(TGraph Graph);

/*----------------ִ��-----------------*/
//�����ڽӾ���ͼ
MGraph BuildAdjMatricGraph();
//�����ڽӾ���ͼ
TGraph BuildAdjTableGraph();