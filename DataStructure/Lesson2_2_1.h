/*********************************
* 栈的顺序存储结构
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct SNode* Stack;
struct SNode {
	int Data[MAXSIZE];
	int Top;
};

//创建空栈
Stack CreateStack(int maxSize);
//判断堆栈S是否已满
int IsFull(Stack PtrS);
//入栈
int Push(Stack PtrS, int item);
//判断是否为空栈
int IsEmpty(Stack PtrS);
//出栈
int Pop(Stack PtrS);
void Invoke2_2_1();

//以下内容未实现调用
//双向堆栈结构
//如:用一个数组实现两个堆栈，要求最大的利用数组空间
typedef struct DStack* Stack2;
struct DStack
{
	int Data[MAXSIZE];
	int Top1;
	int Top2;
};
//双向栈入栈
void Push2(Stack2 PtrS, int item, int Tag);
//双向栈入栈
int Pop2(Stack2 PtrS, int Tag);