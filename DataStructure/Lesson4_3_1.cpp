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

	scanf("%d", &N);//���Ľڵ���

	while (N)//����ڵ���Ϊ0ʱ��ֹ
	{
		scanf("%d", &L);//���жϼ�����
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