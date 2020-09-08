/*********************************
* ջ��˳��洢�ṹ
*********************************/

#include "Lesson2_2_1.h"
#include <stdio.h>
#include <iostream>
//������ջ
Stack CreateStack()
{
	Stack PtrS = (Stack)malloc(sizeof(struct SNode));
	PtrS->Top = -1;
	return PtrS;
}

int IsFull(Stack PtrS)
{
	return (PtrS->Top == MAXSIZE - 1);
}
//��ջ
int Push(Stack PtrS, int item)
{
	if (IsFull(PtrS)) {
		printf("Full of Stack.");
		return -1;
	}
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return 0;
	}
}
//�ж��Ƿ�Ϊ��ջ
int IsEmpty(Stack PtrS)
{
	return (PtrS->Top == -1);
}
//��ջ
int Pop(Stack PtrS)
{
	if (IsEmpty(PtrS)) {
		printf("Empty of Stack");
		return -1;
	}
	else
		return (PtrS->Data[(PtrS->Top)--]);
}

void Invoke2_2_1()
{
	Stack PtrS = CreateStack();
	int i = 0;
	printf("Create A Empty Stack List.\n");
	while (Push(PtrS, i) != -1) i += 5;	
	printf("Current Stack List length is: %d\n", PtrS->Top);
	printf("Current Stack List is:\n");
	int p = Pop(PtrS);
	while (p != -1) {
		printf("Index Of %d Is :%d\n", PtrS->Top, p);
		p = Pop(PtrS);
	}
	return;
}

//˫��ջ��ջ
void Push2(Stack2 PtrS, int item, int Tag)
{
	if (PtrS->Top2 - PtrS->Top1 == 1)
		printf("Full Of Stack");
	if (Tag == 1)
		PtrS->Data[++(PtrS->Top1)] = item;
	else
		PtrS->Data[--(PtrS->Top2)] = item;
}
//˫��ջ��ջ
int Pop2(Stack2 PtrS, int Tag)
{
	if (Tag == 1) {
		if (PtrS->Top1 == -1) {
			printf("Empty of Stack1");
			return NULL;
		}
		else
			return PtrS->Data[(PtrS->Top1)--];
	}
	else {
		if (PtrS->Top2 == MAXSIZE) {
			printf("Empty of Stack2");
			return NULL;
		}
		else
			return PtrS->Data[(PtrS->Top2)--];
	}
}