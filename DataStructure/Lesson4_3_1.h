/*********************************
* 判断是否是相同二叉搜索树
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct TreeNode* Tree;
struct TreeNode {
	int value;
	Tree Left, Right;
	int flag; //标识这个节点访问过
};


Tree MakeTree(int N);
Tree Insert(Tree T, int V);
Tree NewNode(int V);
int Check(Tree T, int V);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);
void Invoke4_3_1();