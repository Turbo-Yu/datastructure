/*********************************
* 队列的链式存储结构
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct Node2* PtrToNode;
struct Node2 {
	int Data;
	PtrToNode Next;
};
typedef PtrToNode Position;
struct QNode2 {
	Position Front,Rear;
};

typedef struct QNode2* Queue2;

Queue2 CreateQueue2();
void Add2(Queue2 PtrQ, int item);
bool IsEmpty2(Queue2 PtrQ);
int Delete2(Queue2 PtrQ);
void Invoke2_3_2();