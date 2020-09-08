/*********************************
* 循环队列的链式存储结构
*********************************/

#include "Lesson2_3_2.h"
#include <stdio.h>
#include <iostream>

Queue2 CreateQueue2()
{
	Queue2 PtrQ = (Queue2)malloc(sizeof(struct QNode2));
	PtrToNode header = (PtrToNode)malloc(sizeof(struct Node2));

	header->Next = NULL;
	PtrQ->Front = PtrQ->Rear = header;
	return PtrQ;
}
void Add2(Queue2 PtrQ, int item)
{
	Position PtrQCell = (Position)malloc(sizeof(struct Node2));
	PtrQCell->Data = item;
	PtrQCell->Next = NULL;
	PtrQ->Rear->Next = PtrQCell;
	PtrQ->Rear = PtrQCell; 
}
bool IsEmpty2(Queue2 PtrQ)
{
	return (PtrQ->Front->Next == NULL);
}
int Delete2(Queue2 PtrQ)
{
	Position FrontCell;
	int FrontElem;
	if (IsEmpty2(PtrQ)) {
		printf("Empty Of Queue.");
		return 0;;
	}
	FrontCell = PtrQ->Front->Next;
	PtrQ->Front->Next = FrontCell->Next;
	FrontElem = FrontCell->Data;

	free(FrontCell);
	return FrontElem;
}
void Invoke2_3_2()
{
	Queue2 PtrQ = CreateQueue2();
	int i = 0;
	while (i<MAXSIZE)
		Add2(PtrQ, i++);

	printf("Current Queue Is:\n");
	while (!IsEmpty2(PtrQ))
		printf("%d\n", Delete2(PtrQ));
	return;
}