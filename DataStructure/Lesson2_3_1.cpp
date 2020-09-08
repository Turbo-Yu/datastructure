/*********************************
* 循环队列的顺序存储结构
*********************************/

#include "Lesson2_3_1.h"
#include <stdio.h>
#include <iostream>

Queue CreateQueue()
{
	Queue q = (Queue)malloc(sizeof(struct QNode));
	q->Front = 0;
	q->Rear = 0;
	return q;
}
int IsFull(Queue PtrQ)
{
	return ((PtrQ->Rear + 1) % MAXSIZE == PtrQ->Front);
}
void Add(Queue PtrQ, int item)
{
	if (IsFull(PtrQ)) {
		printf("Full of Queue.");
		return;
	}
	PtrQ->Rear = (PtrQ->Rear + 1) % MAXSIZE;
	PtrQ->Data[PtrQ->Rear] = item;
}
int IsEmpty(Queue PtrQ)
{
	return (PtrQ->Front == PtrQ->Rear);
}
int Delete(Queue PtrQ)
{
	if (IsEmpty(PtrQ)) {
		printf("Empty of Queue.");
		return 0;
	}
	PtrQ->Front = (PtrQ->Front + 1) % MAXSIZE;
	return PtrQ->Data[PtrQ->Front];
}

void Invoke2_3_1()
{
	Queue PtrQ = CreateQueue();
	int i = 0;
	while (!IsFull(PtrQ)) Add(PtrQ, i++);
	printf("Current Queue Front Point Is : %d.\n", PtrQ->Front);
	printf("Current Queue Rear Point Is : %d.\n", PtrQ->Rear);
	printf("Current Queue Length Is : %d.\n", (PtrQ->Front - PtrQ->Front));
	printf("Current Queue Is:\n");
	while (!IsEmpty(PtrQ)){
		printf("%d:%d\n",PtrQ->Front,Delete(PtrQ));
	}
	return;
}