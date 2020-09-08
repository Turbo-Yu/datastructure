/***************************
* 先建立一个标准树，判断后续输入的内容所建立的树是否与标准树结构相同
* 4 2
* 3 1 4 2
* 3 4 1 2
* 3 2 4 1
* 0
***************************/

#pragma warning(disable:4996)

#include "Lesson4_3_1.h"
#include <stdio.h>
#include <iostream>

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
		if (V > T->value)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}

	return T;
}

Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->value = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;

}

// 判断输入值是否符合标准树的节点结构
// return:0 不同树，1:符合
int Check(Tree T, int V)
{
	if (T->flag)//节点被访问过
	{
		if (V < T->value)//
			return Check(T->Left, V);
		else if (V > T->value)
			return Check(T->Right, V);
		else//同一值出现两次算作不同树
			return 0;
	}
	else//节点未被访问过
	{
		if (V == T->value)//恰好是输入值,标记为访问过
		{
			T->flag = 1;
			return 1;
		}
		return 0;//返回和标准树不同
	}
}

/// 判断是否是相同树
/// 算法说明：
/// 1、对标准树的每个节点增加标识
/// 2、后续输入数据依次访问这棵树并与对应值对比
/// 3、若节点值与输入值不同，且这个节点之前还没被访问过，则认为两棵树不相同。则这个第一次出现的值就是和标准树不同的结构节点
int Judge(Tree T, int N)
{
	int i, V;
	int flag = 0; //标识可以终止查找,0表示尚未找到导致不同结构的值
	scanf("%d", &V);

	if (V == T->value)
		T->flag = 1;
	else
		flag = 1;
	for ( i = 1; i < N; i++)
	{
		scanf("%d", &V);
		if (!flag && (!Check(T, V)))//之前都符合，并且第一次发现不符合的输入值
			flag = 1;//告诉程序，已经找到了不符合的值。后续可以不用判断了
	}
	if (flag)
		return 0;
	else
		return 1;
}

void ResetT(Tree T) /* 清除T中各结点的flag标记 */
{
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}
void FreeTree(Tree T) /* 释放T的空间 */
{
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}


void Invoke4_3_1()
{
	int N, L, i;
	Tree T;

	scanf("%d", &N);//树的节点数

	while (N)//输入节点数为0时终止
	{
		scanf("%d", &L);//将判断几次
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
