#include "Lesson4_3_1.h"

Tree MakeTree(int N)
{
	Tree T;
	int i, V;

	scanf("%d", &V);
	T = NewNode(V);
	for ( i = 1; i < N; i++)
	{
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

Tree Insert(Tree T, int V)
{
	if (!T)
		T = NewNode(V);
	else
	{
		if(V>T->value)
			T->Right = Insert()
	}
}


void Invoke3_1_1()
{
	int N, L, i;
	Tree T;

	scanf("%d", &N);//树的节点数

	while (N)//输入节点数为0时终止
	{
		scanf("%d", &L);//将判断几组树
		T = MakeTree(N);//创建标准树
		for (i = 0; i < L; i++)
		{
			if (Judge(T, N))//和标准树比较输入的树节点
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T);//重置标准树的Flag标识
		}
		FreeTree(T);
		scanf("%d", &N);//下一组的树的节点数
	}
}