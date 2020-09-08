/*********************************
* 线性表的顺序存储结构
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
		PtrL->Data[j + 1] = PtrL->Data[j];//先将i之后的元素向后移动
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
		PtrL.Data[j + 1] = PtrL.Data[j];//先将i之后的元素向后移动
	PtrL.Data[i - 1] = x;
	PtrL.Length++;
	return;
}

void Delete(int i, List PtrL)
{
	int j;
	if (i<1 || i > PtrL->Length + 1) {
		printf("不存在第%d个元素", i);
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
	List PtrL = MakeEmpty();//构造空线性表
	for (int i = 0; i < MAXSIZE; i++)
		Insert(i, i + 1, PtrL);//填充数值
	printf("Current List length is: %d\n", PtrL->Length);
	printf("Current List is:\n");
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d:%d\n",i,PtrL->Data[i]);
	}

	printf("Inert 50 to current list.\n");
	Insert(50, 4, PtrL);//插入50数值
	printf("The index of 50 in list is %d.\n", Find(50, PtrL));//查找50
	printf("Delete the value of index 3 in current list.\n");
	Delete(3, PtrL);//删除第三个元素
	printf("Current List length is: %d\n", PtrL->Length);
	printf("Current List is:\n");
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d:%d\n", i, PtrL->Data[i]);
	}
	return;
}

//移除数列中的最小值 T=O(n)
bool RemoveMinValue(LNode &L,ElementType x )
{
	if (L.Length <= 0)
		return false;
	x = L.Data[0];
	int pos = 0;//最小值的位置
	for (int i = 0; i < L.Length; i++)
	{
		if (L.Data[i] < x)
		{
			x = L.Data[i];//最小值
			pos = i;
		}
	}
	L.Data[pos] = L.Data[L.Length--];//用最后一位替换最小值
	return true;
}

//逆置数列 T=O(n) S=O(1)
void Reset(LNode& L)
{
	ElementType temp;
	for (int i = 0; i < L.Length / 2; i++)
	{
		temp = L.Data[i];
		L.Data[i] = L.Data[L.Length - i - 1]; //交换第i和第n-i项
		L.Data[L.Length - i - 1] = temp;
	}
}

//删除数列中值为x的元素 T=O(n) S=O(1)
void RemoveAllRepeat(LNode& L, ElementType x)
{
	int k = 0;//不等于x的元素的下标
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

//删除大于s小于t的元素 T=O(n)
bool RemoveSpan(LNode& L, ElementType s, ElementType t)
{
	if (L.Length == 0 || s > t)
		return false;
	int k = 0;//记录在s至t之间的元素个数
	for (int i = 0; i < L.Length; i++)
	{
		if (L.Data[i] >= s && L.Data[i] <= t)
		{
			k++;
		}
		else//小于s和大于t
		{
			L.Data[i - k] = L.Data[i];//将大于t的元素向前移动k
		}
	}
	if (k == 0)
		return false;
	L.Length -= k;
	return true;
}

//有序数列去重
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

//合并两个有序数列到一个有序数列
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
		Insert(i, i + 1, L1);//填充数值
		Insert(i, i + 3, L2);//填充数值
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