/*********************************
* 队列的顺序存储结构
*********************************/
#include <stdio.h>
#define MAXSIZE 10

struct QNode {
	int Data[MAXSIZE];
	int Rear;
	int Front;
};

typedef struct QNode* Queue;

Queue CreateQueue();
int IsFull(Queue PtrQ);
void Add(Queue PtrQ, int item);
int IsEmpty(Queue PtrQ);
int Delete(Queue PtrQ);
void Invoke2_3_1();