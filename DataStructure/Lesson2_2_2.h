/*********************************
* 栈的链式存储结构
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct SNode* Stack;
struct SNode {
	int Data;
	struct SNode* Next;
};

//创建空栈
Stack CreateStack_S(int maxSize);
//入栈
void Push_S(Stack PtrS, int item);
//判断是否为空栈
int IsEmpty_S(Stack PtrS);
//出栈
int PopS(Stack PtrS);
void Invoke2_2_2();