/***************************
* �Ƚ���һ����׼�����жϺ�����������������������Ƿ����׼���ṹ��ͬ
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

// �ж�����ֵ�Ƿ���ϱ�׼���Ľڵ�ṹ
// return:0 ��ͬ����1:����
int Check(Tree T, int V)
{
	if (T->flag)//�ڵ㱻���ʹ�
	{
		if (V < T->value)//
			return Check(T->Left, V);
		else if (V > T->value)
			return Check(T->Right, V);
		else//ͬһֵ��������������ͬ��
			return 0;
	}
	else//�ڵ�δ�����ʹ�
	{
		if (V == T->value)//ǡ��������ֵ,���Ϊ���ʹ�
		{
			T->flag = 1;
			return 1;
		}
		return 0;//���غͱ�׼����ͬ
	}
}

/// �ж��Ƿ�����ͬ��
/// �㷨˵����
/// 1���Ա�׼����ÿ���ڵ����ӱ�ʶ
/// 2�����������������η�������������Ӧֵ�Ա�
/// 3�����ڵ�ֵ������ֵ��ͬ��������ڵ�֮ǰ��û�����ʹ�������Ϊ����������ͬ���������һ�γ��ֵ�ֵ���Ǻͱ�׼����ͬ�Ľṹ�ڵ�
int Judge(Tree T, int N)
{
	int i, V;
	int flag = 0; //��ʶ������ֹ����,0��ʾ��δ�ҵ����²�ͬ�ṹ��ֵ
	scanf("%d", &V);

	if (V == T->value)
		T->flag = 1;
	else
		flag = 1;
	for ( i = 1; i < N; i++)
	{
		scanf("%d", &V);
		if (!flag && (!Check(T, V)))//֮ǰ�����ϣ����ҵ�һ�η��ֲ����ϵ�����ֵ
			flag = 1;//���߳����Ѿ��ҵ��˲����ϵ�ֵ���������Բ����ж���
	}
	if (flag)
		return 0;
	else
		return 1;
}

void ResetT(Tree T) /* ���T�и�����flag��� */
{
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}
void FreeTree(Tree T) /* �ͷ�T�Ŀռ� */
{
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}


void Invoke4_3_1()
{
	int N, L, i;
	Tree T;

	scanf("%d", &N);//���Ľڵ���

	while (N)//����ڵ���Ϊ0ʱ��ֹ
	{
		scanf("%d", &L);//���жϼ���
		T = MakeTree(N);//������׼��
		for (i = 0; i < L; i++)
		{
			if (Judge(T, N))//�ͱ�׼���Ƚ���������ڵ�
				printf("Yes\n");
			else
				printf("No\n");
			ResetT(T);//���ñ�׼����Flag��ʶ
		}
		FreeTree(T);
		scanf("%d", &N);//��һ������Ľڵ���
	}
}
