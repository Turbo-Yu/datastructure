/*********************************
* ջ��˳��洢�ṹ
*********************************/
#include <stdio.h>
#define MAXSIZE 10

typedef struct SNode* Stack;
struct SNode {
	int Data[MAXSIZE];
	int Top;
};

//������ջ
Stack CreateStack(int maxSize);
//�ж϶�ջS�Ƿ�����
int IsFull(Stack PtrS);
//��ջ
int Push(Stack PtrS, int item);
//�ж��Ƿ�Ϊ��ջ
int IsEmpty(Stack PtrS);
//��ջ
int Pop(Stack PtrS);
void Invoke2_2_1();

//��������δʵ�ֵ���
//˫���ջ�ṹ
//��:��һ������ʵ��������ջ��Ҫ��������������ռ�
typedef struct DStack* Stack2;
struct DStack
{
	int Data[MAXSIZE];
	int Top1;
	int Top2;
};
//˫��ջ��ջ
void Push2(Stack2 PtrS, int item, int Tag);
//˫��ջ��ջ
int Pop2(Stack2 PtrS, int Tag);