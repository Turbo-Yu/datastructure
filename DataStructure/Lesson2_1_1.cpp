/*********************************
* ���Ա��˳��洢�ṹ
*********************************/

#include "Lesson2_1_1.h"
#include <stdio.h>
#include <iostream>

List MakeEmpty()
{
	List PtrL;
	PtrL = (List)malloc(sizeof(struct LNode));
	PtrL->Length = 0;
	return PtrL;
}

LNode* MakeEmptyNode()
{
	LNode* PtrL;
	PtrL = (LNode*)malloc(sizeof(struct LNode));
	PtrL->Length = 0;
	return PtrL;
}

int Find(ElementType x, List PtrL)
{
	int i = 0;
	while (i <= PtrL->Length && PtrL->Data[i] != x)
		i++;
	if (i > PtrL->Length)
		return -1;
	else
		return i;
}

void Insert(ElementType x, int i, List PtrL)
{
	int j;
	if (PtrL->Length == (MAXSIZE - 1)) {
		printf("Full List");
		return;
	}
	if (i<1 || i > PtrL->Length + 2) {
		printf("Invalid Value");
		return;
	}
	for (j = PtrL->Length; j == i - 1; j--)
		PtrL->Data[j + 1] = PtrL->Data[j];//�Ƚ�i֮���Ԫ������ƶ�
	PtrL->Data[i - 1] = x;
	PtrL->Length++;
	return;
}

void Insert(ElementType x, int i, LNode &PtrL)
{
	int j;
	if (PtrL.Length == (MAXSIZE - 1)) {
		printf("Full List");
		return;
	}
	if (i<1 || i > PtrL.Length + 2) {
		printf("Invalid Value");
		return;
	}
	for (j = PtrL.Length; j == i - 1; j--)
		PtrL.Data[j + 1] = PtrL.Data[j];//�Ƚ�i֮���Ԫ������ƶ�
	PtrL.Data[i - 1] = x;
	PtrL.Length++;
	return;
}

void Delete(int i, List PtrL)
{
	int j;
	if (i<1 || i > PtrL->Length + 1) {
		printf("�����ڵ�%d��Ԫ��", i);
		return;
	}
	for (j = i; j < PtrL->Length; j++) {
		PtrL->Data[j - 1] = PtrL->Data[j];
	}
	PtrL->Length--;
	return;
}

void Invoke2_1_1()
{
	List PtrL = MakeEmpty();//��������Ա�
	for (int i = 0; i < MAXSIZE; i++)
		Insert(i, i + 1, PtrL);//�����ֵ
	printf("Current List length is: %d\n", PtrL->Length);
	printf("Current List is:\n");
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d:%d\n",i,PtrL->Data[i]);
	}

	printf("Inert 50 to current list.\n");
	Insert(50, 4, PtrL);//����50��ֵ
	printf("The index of 50 in list is %d.\n", Find(50, PtrL));//����50
	printf("Delete the value of index 3 in current list.\n");
	Delete(3, PtrL);//ɾ��������Ԫ��
	printf("Current List length is: %d\n", PtrL->Length);
	printf("Current List is:\n");
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d:%d\n", i, PtrL->Data[i]);
	}
	return;
}

//�Ƴ������е���Сֵ T=O(n)
bool RemoveMinValue(LNode &L,ElementType x )
{
	if (L.Length <= 0)
		return false;
	x = L.Data[0];
	int pos = 0;//��Сֵ��λ��
	for (int i = 0; i < L.Length; i++)
	{
		if (L.Data[i] < x)
		{
			x = L.Data[i];//��Сֵ
			pos = i;
		}
	}
	L.Data[pos] = L.Data[L.Length--];//�����һλ�滻��Сֵ
	return true;
}

//�������� T=O(n) S=O(1)
void Reset(LNode& L)
{
	ElementType temp;
	for (int i = 0; i < L.Length / 2; i++)
	{
		temp = L.Data[i];
		L.Data[i] = L.Data[L.Length - i - 1]; //������i�͵�n-i��
		L.Data[L.Length - i - 1] = temp;
	}
}

//ɾ��������ֵΪx��Ԫ�� T=O(n) S=O(1)
void RemoveAllRepeat(LNode& L, ElementType x)
{
	int k = 0;//������x��Ԫ�ص��±�
	for (int i = 0; i < L.Length; i++)
	{
		if (L.Data[i] != x)
		{
			L.Data[k] = L.Data[i];
			k++;
		}
	}
	L.Length = k;
}

//ɾ������sС��t��Ԫ�� T=O(n)
bool RemoveSpan(LNode& L, ElementType s, ElementType t)
{
	if (L.Length == 0 || s > t)
		return false;
	int k = 0;//��¼��s��t֮���Ԫ�ظ���
	for (int i = 0; i < L.Length; i++)
	{
		if (L.Data[i] >= s && L.Data[i] <= t)
		{
			k++;
		}
		else//С��s�ʹ���t
		{
			L.Data[i - k] = L.Data[i];//������t��Ԫ����ǰ�ƶ�k
		}
	}
	if (k == 0)
		return false;
	L.Length -= k;
	return true;
}

//��������ȥ��
void DistinctSeq(LNode& L)
{
	int k = 0, s = 0;
	for (size_t i = 0; i < L.Length; i++)
	{
		if (L.Data[i] == L.Data[i + 1])
		{
			k++;
		}
		else
		{
			L.Data[i - k] = L.Data[i];
		}
	}
}

//�ϲ������������е�һ����������
bool CombineSeq(LNode& L1, LNode& L2,LNode & L)
{
	if (L1.Length + L2.Length > MAXSIZE)
		return false;
	int i1 = 0, i2 = 0;
	while(L.Length < L1.Length + L2.Length + 1)
	{
		if (L1.Data[i1] <= L2.Data[i2])
		{
			L.Data[i1 + i2] = L1.Data[i1];
			i1++;
		}
		else
		{
			L.Data[i1 + i2] = L2.Data[i2];
			i2++;
		}
		L.Length++;
	}
	return true;
}

void Test_CombineSeq()
{
	struct LNode L1 = { {},0 };
	struct LNode L2 = { {},0 };
	struct LNode L = { {},0 };
	for (size_t i = 0; i < 7; i++)
	{
		Insert(i, i + 1, L1);//�����ֵ
		Insert(i, i + 3, L2);//�����ֵ
	}
	for (size_t i = 0; i < 7; i++)
	{
		printf("L1[%d]:%d,\n", i, L1.Data[i]);
		printf("L2[%d]:%d,\n", i, L2.Data[i]);
	}
	if (CombineSeq(L1,L2,L))
	{
		for (size_t i = 0; i < 14; i++)
		{
			printf("L[%d]:%d,\n", i, L.Data[i]);
		}

	}
	else {
		printf("Error Formation.");
	}
}