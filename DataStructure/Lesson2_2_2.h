/*********************************
* ջ����ʽ�洢�ṹ
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct SNode* Stack;
struct SNode {
	int Data;
	struct SNode* Next;
};

//������ջ
Stack CreateStack_S(int maxSize);
//��ջ
void Push_S(Stack PtrS, int item);
//�ж��Ƿ�Ϊ��ջ
int IsEmpty_S(Stack PtrS);
//��ջ
int PopS(Stack PtrS);
void Invoke2_2_2();