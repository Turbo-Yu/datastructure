/*********************************
* 栈的链式存储结构
*********************************/
#include "Lesson2_2_2.h"
#include <stdio.h>
#include <iostream>

Stack CreateStackS()
{
	Stack p = (Stack)malloc(sizeof(struct SNode));
	p->Next = NULL;
	return p;
}

void PushS(Stack PtrS, int item)
{
	struct SNode* TmpCell;
	TmpCell = (Stack)malloc(sizeof(struct SNode));
	TmpCell->Data = item;
	TmpCell->Next = PtrS->Next;
	PtrS->Next = TmpCell;
}

int IsEmptyS(Stack PtrS)
{
	return (PtrS->Next == NULL);
}

int PopS(Stack PtrS)
{
	struct SNode* FirstCell;
	int TopElem;
	if (IsEmptyS(PtrS)) {
		printf("Empty of Stack.");
		return NULL;
	}
	else {
		FirstCell = PtrS->Next;
		PtrS->Next = FirstCell->Next;
		TopElem = FirstCell->Data;
		free(FirstCell);
		return TopElem;
	}
}

void Invoke2_2_2()
{
	Stack PtrS = CreateStackS();
	int i = 0;
	while (i < MAXSIZE) {
		PushS(PtrS,i++);
	}
	printf("Current List is:\n");
	int p = PopS(PtrS);
	while (p != NULL) {
		printf("%d\n", p);
		p = PopS(PtrS);
	}
	return;
}